#include "../includes/Server.hpp"

bool	Server::checkRequest(int fd) {
	sBMap alllowed_methods = _config.getAllowedMethods();
	if (alllowed_methods[_requestMap["HTTP_method"]] == false)
		return default_error_answer(405, fd);
	return true;
}

void	Server::parseRequest(std::string request) {
	std::size_t first = 0;
	std::size_t find = 0;
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

void Server::handleRequest(int fd) {
	std::string	methods[5] = {"GET", "POST", "DELETE", "HEAD", "PUT"};
	int	i;

	for (i = 0; i < 5; i++)
		if (methods[i] == _requestMap["HTTP_method"])
			break ;
	std::cout << methods[i] << std::endl;
	switch(i)
	{
		case GET:
			this->handleGET(fd);
			break ;
		case DELETE:
			this->handleDELETE(fd);
			break;
		default :
			this->default_error_answer(404, fd);
			return ;
	}
}

void	Server::handleDELETE(int fd) {
	std::string url = _requestMap["URL"];
	Config		toDeleteLocation = _locationMap[url];
}

void	Server::handleGET(int fd) {
	std::ifstream body;

    if (!getBody(body, fd))
        return ;
	std::ostringstream oss;
	std::string b( (std::istreambuf_iterator<char>(body) ),
                       (std::istreambuf_iterator<char>()    ) );
	oss << "HTTP/1.1 200 OK\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << b.size() << "\r\n";
    // oss << "Connection: keep-alive\r\n";
    oss << "\r\n";
    oss << b;
	oss << "\r\n\n\r";
	std::string response(oss.str());

	if (send(fd, response.c_str(), response.size(), MSG_NOSIGNAL) == -1)
		std::cout << "Send error!\n";
// 	std::cout<< "send fd:" << fd << std::endl;
// 	std::cout << "root " << _config.getRoot() << " index: " << _config.getIndex().at(0) << std::endl;
// 	if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, MSG_NOSIGNAL) == -1)
// 		std::cout << "Send error!\n";
}

bool Server::getBody(std::ifstream &body, int fd) {
	sVec	url;

	url.push_back(_requestMap["URL"]);
	if (_requestMap["URL"] == "/")
		url = _config.getIndex();
	for (sVec::iterator it = url.begin(); it != url.end(); it++)
	{
		body.open(_config.getRoot() + "/" + *it);
		if (body.is_open() == true)
			return true;
	}
	this->default_error_answer(404, fd);
	return false;
}