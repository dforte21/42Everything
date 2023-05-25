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
	_serverVecSize = _serverVec.size();
	for(std::vector<Server>::iterator it = _serverVec.begin(); it != _serverVec.end(); it++) {
		Pfds pfds(it->getServerSocket());
		_PfdsVec.push_back(pfds);
	}
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

void	Cluster::startListening() {
	int poll_count;

	for (;;) {
		for (std::vector<Pfds>::iterator it = _PfdsVec.begin(); it != _PfdsVec.end(); it++) {
			poll_count = poll(it->getSocketArr(), it->getCount(), -1);
			if (poll_count == -1)
				throw std::runtime_error("Poll error");
			if (poll_count > 0)
				this->listen(*it);
		}
	}
}

void	Cluster::listen(Pfds &pfds) {
	int new_fd;
	struct sockaddr_storage client_addr;
	socklen_t sin_size = sizeof(client_addr);
	struct pollfd *socketArr = pfds.getSocketArr();
		for(int i = 0; i < pfds.getCount(); i++) {
			// if (socketArr[i].revents & POLLIN){ // tolta temporaneamente perché poll non aggiorna revents
				if (i == 0) { //listener
					new_fd = accept(socketArr[0].fd, (struct sockaddr *)&client_addr, &sin_size);
					if (new_fd == -1)
						throw std::runtime_error("Accept error");
					else {
						pfds.addToPfds(new_fd);
						std::cout << "new_fd:" << new_fd << std::endl;
					}
				}
				else { //client
					char buf[256];
					int nbytes = 0;
					std::string request;
					while (1) {
						nbytes += recv(socketArr[i].fd, buf, 255, 0);
						if (nbytes == 0)
							break ;
						else if (nbytes < 0){
							std::cout << "Recv error\n";
							close(socketArr[i].fd);
							pfds.delFromPfds(i);
							std::cout << "Connection from " << socketArr[i].fd << " closed.\n";
							break ;
						}
						buf[nbytes] = '\0';
						request += buf;
						size_t diopo;
						if (request.find("\r\n\r\n") != std::string::npos)
							break ;
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
					this->handle_request(tok_http, socketArr[i].fd);
					// close(pfds[i].fd);
					// del_frompfds(pfds, i, &_serverVecSize);
				}
			// }
		}
}

void Cluster::handle_request(std::map<std::string, std::string> http_map, int fd) {
	// if (http_map.empty())
	// 	return ;
	// std::map<std::string, bool>::iterator it = _serverConfig.getAllowedMethods().find(http_map.at("HTTP_method"));
	// if (it == _serverConfig.getAllowedMethods().end() || it->second == false)
	// 	this->default_error_answer(405, fd);
	// else
	std::cout<< "fd:" << fd << std::endl;
		if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
							std::cout << "Send error!\n";
		
}

std::map<std::string, std::string> Cluster::parse_request(std::string request) {
	std::size_t first = 0;
	std::size_t find = 0;
	std::size_t i = 0;

	const char *prova = request.c_str();
	std::map<std::string, std::string> map;
	std::string line;

	while (prova[i] != '\0') {
		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
			line = request.substr(first, i - first);
			// std::cout << "firstline: " << line << std::endl;
			std::size_t space = line.find(' ', 0);
			std::size_t space2 = line.find(' ', space + 1);
			map.insert(std::pair<std::string, std::string>("HTTP_method", line.substr(0, space)));
			map.insert(std::pair<std::string, std::string>("URL", line.substr(space + 1, space2 - space)));
			map.insert(std::pair<std::string, std::string>("protocol_version", line.substr(space2 + 1, line.length())));
			if (prova[i] != 4)
				i++;
			first = i + 1;
			break ;
		}
		i++;
	}
	while (prova[i] != '\0') {
		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
			line = request.substr(first, i - first);
			if (prova[i] != 4)
				i++;
			first = i + 1;
		std::size_t mid = line.find(':', 0);
		if (mid != std::string::npos && line[mid] == ':' && line[mid + 1] == ' ')
			map.insert(std::pair<std::string, std::string>(line.substr(0, mid), line.substr(mid + 2 , line.length())));
		else
			map.insert(std::pair<std::string, std::string>(line.substr(0, line.length()), ""));
		}
		i++;
	}
	return map;
}

const char *Cluster::wrongFilePath::what() const throw() {
	return "Wrong file path";
}

const char *Cluster::badConfigFile::what() const throw() {
	return "Bad config file";
}