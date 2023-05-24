#include "../includes/Cluster.hpp"

Cluster::Cluster(const char *filePath) {
	std::ifstream	configFile;
	std::string		fileContent;
	sVec			serverBodyVec;


	if (filePath == NULL)
		filePath = "default.conf";
	configFile.open(filePath);
	if (!configFile.is_open())
		throw wrongFilePath();
	std::getline(configFile, fileContent, '\0');
	for(size_t pos = fileContent.find_first_of("#"); pos != std::string::npos; pos = fileContent.find_first_of("#"))
		fileContent.erase(pos, fileContent.find_first_of("\n", pos) - pos);
	serverBodyVec = this->divideByServer(fileContent);
	for(sVec::iterator it = serverBodyVec.begin(); it != serverBodyVec.end(); it++)
	{
		Config	config(*it);
		this->displayServerConfig(config);
		_serverVec.push_back(config);
	}
	this->setPfds();
	this->startListening();
}

Cluster::~Cluster(void) {

}

sVec	Cluster::divideByServer(std::string &fileContent) {
	size_t	bodyLen;
	sVec	serverBodyVec;

	if (fileContent.find_first_not_of(" \t\n") < fileContent.find("server"))
		throw badConfigFile();
	else if (fileContent.find_first_not_of(" \t\n", (fileContent.find("server") + 6)) < fileContent.find_first_of("{"))
		throw badConfigFile();
	for (int begin = fileContent.find_first_of("{"); begin != std::string::npos; begin = fileContent.find_first_of("{", begin + bodyLen))
	{
		bodyLen = 0;
		for (int bracketsCount = 0; begin + bodyLen < fileContent.length();)
		{
			if (fileContent.at(begin + bodyLen) == '{')
				bracketsCount++;
			else if (fileContent.at(begin + bodyLen) == '}')
				bracketsCount--;
			bodyLen++;
			if (bracketsCount == 0)
				break ;
		}
		if (fileContent.at(begin + bodyLen - 1) != '}')
			throw badConfigFile();
		if (fileContent.find_first_not_of(" \n", begin + bodyLen) < fileContent.find("server", begin + bodyLen))
		 	throw badConfigFile();
		if (fileContent.find("server", begin + bodyLen) != std::string::npos &&
			fileContent.find_first_not_of(" \n", fileContent.find("server", begin + bodyLen) + 6) < fileContent.find_first_of("{", begin + bodyLen))
				throw badConfigFile();
		serverBodyVec.push_back(fileContent.substr(begin, bodyLen));
	}
	return serverBodyVec;
}

void	Cluster::displayServerConfig(Config &config) const {
	sCMap 			locationMap;

	std::cout << "Server" << std::endl;
	config.displayConfig();
	locationMap = config.getLocationMap();
	for (sCMap::iterator it = locationMap.begin(); it != locationMap.end(); it++)
	{
		std::cout << "Name: " << it->first << std::endl;
		it->second.displayConfig();
	}
}


void	Cluster::setPfds(void) {
	_pfdsSize = _serverVec.size() * 2;
	_pfds = (struct pollfd *)malloc(sizeof _pfds * _pfdsSize);
	int i = 0;
	for(std::vector<Server>::iterator it = _serverVec.begin(); it != _serverVec.end(); it++, i++)
	{
		_pfds[i].fd = it->getServerSocket();
		_pfds[i].events = POLLIN;
	}
}

void	Cluster::startListening() {
	_pfds[0].events = POLLIN;
	std::vector<std::string> rest;
	rest.resize(_pfdsSize);
	int poll_count = 0;
	int new_fd;
	struct sockaddr_storage client_addr;
	socklen_t sin_size = sizeof(client_addr);
	for (;;) {
		poll_count = poll(_pfds, _serverVec.size(), -1);
		if (poll_count == -1)
			throw std::runtime_error("Poll error");
		int pollin_count = 0;
		for(int i = 0; i < _serverVec.size(); i++) {
			if (_pfds[i].revents & POLLIN){
				if (i < _serverVec.size()) { //listener
					new_fd = accept(_pfds[i].fd, (struct sockaddr *)&client_addr, &sin_size);
					if (new_fd == -1)
						throw std::runtime_error("Accept error");
					else {
						add_to__pfds(_pfds, new_fd, &_serverVec.size(), &_pfdsSize);
						if (rest.capacity() < _pfdsSize)
							rest.resize(_pfdsSize);
						std::cout << "new_fd:" << new_fd << std::endl;
					}
				}
				else { //client
					char buf[256];
					int nbytes = 0;
					std::string request;
					if (rest.at(i).empty() == false)
						request + rest.at(i);
					while (1) {
						nbytes += recv(_pfds[i].fd, buf, 255, 0);
						// std::cout<< "nbytes:"<< nbytes << std::endl;
						if (nbytes == 0) {
							// std::cout << "Connection from " << _pfds[i].fd << " fine recv(0).\n";
							break ;
						}
						else if (nbytes < 0){
							std::cout << "Recv error\n";
							close(_pfds[i].fd);
							del_from_pfds(_pfds, i, &_serverVec.size());
							std::cout << "Connection from " << _pfds[i].fd << " closed.\n";
							break ;
						}
						buf[nbytes] = '\0';
						request += buf;
						size_t diopo;
						if ((diopo = request.find("\r\n\r\n")) != std::string::npos){
							if (diopo + 4 < nbytes)
								rest.at(i) = request.substr(diopo + 4, request.size() - (diopo + 4));
							else if (rest.empty() == false)
								rest.at(i).clear();
							break ;
						}
					}
					// if (request != "")
					// 	std::cout<< "\n REQUEST:\n "<< request << std::endl;
					std::map<std::string, std::string> tok_http = this->parse_request(request);
					// if (tok_http.empty() == true)
					// 	std::cout<<"Mappa tokenizzata vuota!\n\n\n";
					// for (std::map<std::string, std::string>::iterator it = tok_http.begin();
					// 		it != tok_http.end(); it++) {
					// 			std::cout << "\nfirst:" << it->first << " second:" << it->second << std::endl;
					// }
					this->handle_request(tok_http, _pfds[i].fd);
					// close(_pfds[i].fd);
					// del_from_pfds(pfds, i, &_serverVec.size());
				}
				pollin_count++;
				if (pollin_count == poll_count)
					break ;
			}
		}
	}
}

const char *Cluster::wrongFilePath::what() const throw() {
	return "Wrong file path";
}

const char *Cluster::badConfigFile::what() const throw() {
	return "Bad config file";
}