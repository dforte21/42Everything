#include "../includes/Server.hpp"

bool	Server::checkRequest(int fd, Config &location) {
	//location = _locationMap["/"];
	std::string temp_request = _requestMap["URL"];
	if (_locationMap.count(temp_request) == 0) {
		size_t pos = temp_request.size();
		while ((pos = temp_request.rfind('/', pos)) != std::string::npos){
			temp_request.resize(pos);
			if (_locationMap.count(temp_request) > 0) {
				location = _locationMap[temp_request];
				location._location_name = temp_request;
				break ;
			}
			location = _locationMap["/"];
			location._location_name = "/";
		}
	}
	else {
		location = _locationMap[temp_request];
		location._location_name = temp_request;
	}
	sBMap alllowed_methods = location.getAllowedMethods();
	if (alllowed_methods[_requestMap["HTTP_method"]] == false) {
		default_error_answer(405, fd, location);
		return false;
	}
	return true;
}

void	Server::parseRequest(std::string request) {
	std::size_t first = 0;
	std::size_t i = 0;

	const char *prova = request.c_str();
	std::string line;

	while (prova[i] != '\0') {
		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
			line = request.substr(first, i - first);
			std::size_t space = line.find(' ', 0);
			std::size_t space2 = line.find(' ', space + 1);
			_requestMap.insert(std::make_pair("HTTP_method", line.substr(0, space)));
			_requestMap.insert(std::make_pair("URL", line.substr(space + 1, space2 - space - 1)));
			_requestMap.insert(std::make_pair("protocol_version", line.substr(space2 + 1, line.length())));
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
			_requestMap.insert(std::make_pair(line.substr(0, mid), line.substr(mid + 2 , line.length())));
		else
			_requestMap.insert(std::make_pair(line.substr(0, line.length()), ""));
		}
		i++;
	}
}

void Server::handleRequest(int fd, Config location) {
	std::string	methods[5] = {"GET", "POST", "DELETE", "HEAD", "PUT"};
	int	i;

	for (i = 0; i < 5; i++)
		if (methods[i] == _requestMap["HTTP_method"])
			break ;
	//std::cout << methods[i] << std::endl;
	switch(i)
	{
		case GET:
			this->handleGET(fd, location);
			break ;
		case DELETE:
			this->handleDELETE(fd);
			break;
		default :	
			return this->default_error_answer(405, fd, location);
	}
}

void	Server::handleDELETE(int fd) {
	std::string url = _requestMap["URL"];
	Config		toDeleteLocation = _locationMap[url];

	(void)fd;
}

void	Server::handleGET(int fd, Config location) {
	std::ifstream body;
	int status;
	std::cout<< "handleGET "<< _requestMap["URL"] << std::endl;
	if (_requestMap["URL"] == "/favicon.ico")
		return getIcon(body, fd, location);
	std::cout<< "location name:" << location._location_name << std::endl;
	if ((status = getBody(body, location)) != 0)
		return default_error_answer(status, fd, location);
	std::cout<< "non va in errore\n";
	std::string b( (std::istreambuf_iterator<char>(body) ),
                       (std::istreambuf_iterator<char>()    ) );
	std::ostringstream oss;
	oss << "HTTP/1.1 200 OK\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << b.size() << "\r\n";
    // oss << "Connection: keep-alive\r\n";
    oss << "\r\n";
    oss << b;
	//oss << "\r\n\n\r"; //forse non va messo, sembra che il tester dia un errore
	std::string response(oss.str());

	if (send(fd, response.c_str(), response.size(), MSG_NOSIGNAL) == -1)
		std::cout << "Send error!\n";
// 	std::cout<< "send fd:" << fd << std::endl;
// 	std::cout << "root " << _config.getRoot() << " index: " << _config.getIndex().at(0) << std::endl;
// 	if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, MSG_NOSIGNAL) == -1)
// 		std::cout << "Send error!\n";
}

int Server::getBody(std::ifstream &body, Config location) {
	std::string resource_path = _requestMap["URL"];
	std::string root = location.getRoot();

	if (root.at(root.size() - 1) != '/')
		root += "/";
	if (location._location_name == "/") {
		resource_path = root;
	}
	else {
		std::cout<<"resource_path prima:"<<resource_path<<std::endl;
		size_t pos = resource_path.find(location._location_name);

		resource_path.replace(pos, location._location_name.size(), root);
		pos = resource_path.find("//");
		std::cout << "find pos:"<< pos<<" resource.size:"<< resource_path.size()<<std::endl;
		if (pos != std::string::npos)
			resource_path.erase(pos, 1);
		std::cout<<"resource_path at size -1:"<<resource_path.at(resource_path.size() - 1) <<std::endl;
	}
	if (!isDirectory(resource_path)) {
		body.open(resource_path.c_str());
		if (body.is_open() == true){std::cout<<"no dir open file"<<std::endl;
				return 0;}
		else
			body.close();
	}
	if (resource_path.at(resource_path.size() - 1) != '/')
		resource_path.push_back('/');
	std::cout<<"resource path:"<<resource_path<<std::endl;
	sVec	indexes = location.getIndex();
	for (sVec::iterator it = indexes.begin(); it != indexes.end(); it++)
	{
		std::cout<< "tentativo: " << resource_path + *it << std::endl;
		body.open((resource_path + *it).c_str());
		if (body.is_open() == true)
			return 0;
		body.close();
	}

	std::cout<<"final return"<< std::endl;
	return 404;
}

void Server::getIcon(std::ifstream &body, int fd, Config location) {
	body.open("fake_site/choco.png");
	if (body.is_open() == false)
		return default_error_answer(404, fd, location);
	std::string b( (std::istreambuf_iterator<char>(body) ),
					(std::istreambuf_iterator<char>()) );
	std::ostringstream oss;
	oss << "HTTP/1.1 200 OK\r\n";
	oss << "Content-Type: image/png\r\n";
	oss << "Content-Length: " << b.size() << "\r\n";
	oss << "\r\n";
	oss << b;
	//oss << "\r\n\n\r";
	std::string response(oss.str());
	if (send(fd, response.c_str(), response.size(), MSG_NOSIGNAL) == -1)
		std::cout << "Send error!\n";
}

bool isDirectory(const std::string& path) {
	struct stat fileStat;
	if (stat(path.c_str(), &fileStat) == 0)
		return S_ISDIR(fileStat.st_mode);
	return false;
}