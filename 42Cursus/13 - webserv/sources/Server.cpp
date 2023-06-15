#include "../includes/Server.hpp"

Server::Server(Config &config, sCMap &locationMap) : _config(config), _locationMap(locationMap) {
	struct sockaddr_in	addr;
	int					listener;

	listener = socket(AF_INET, SOCK_STREAM, 0);
	fcntl(listener, F_SETFL, O_NONBLOCK); //questo é il non bloccante
	if (listener < 0)
		throw std::runtime_error("Unable to create socket");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(config.getListen()); //probabilmente da cambiare
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int yes = 1;
	if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1)
		throw std::runtime_error("Unable to reuse port");
	if (bind(listener,(struct sockaddr *)&addr, sizeof(addr)) < 0)
		throw std::runtime_error("Unable to bind socket");
	if (listen(listener, 1000) < 0)
		throw std::runtime_error("Listen error");
	_pfds.addToPfds(listener);
	std::cout << "server = " << listener << std::endl;
}

Server::~Server(void) {

}

void	Server::startListening(void) {
	int 			poll_count;
	struct pollfd	*socketArr;

	socketArr = _pfds.getSocketArr();
	poll_count = poll(socketArr, _pfds.getCount(), 0);
	if (poll_count == -1)
		throw std::runtime_error("Poll error");
	if (poll_count == 0)
		return ;
	std::cout << socketArr[0].fd << " poll count " << poll_count << "\n";
	for(int i = 0; i < _pfds.getCount(); i++)
	{
		if (socketArr[i].revents & POLLIN)
		{
			if (i == 0){
				std::cout << "(handle server) nuovo socket!\n";
				this->handleServer();
				}
			else
				this->handleClient(i);
		}
	};
}


void	Server::handleServer(void) {
	int 					new_fd;
	struct sockaddr_storage client_addr;
	socklen_t				sin_size;
	struct pollfd			*socketArr;

	sin_size = sizeof(client_addr);
	socketArr = _pfds.getSocketArr();
	new_fd = accept(socketArr[0].fd, (struct sockaddr *)&client_addr, &sin_size);
	if (new_fd == -1)
		throw std::runtime_error("Accept error");
	_pfds.addToPfds(new_fd);
	std::cout << "new_fd:" << new_fd << std::endl;
}

void	Server::handleClient(int i) {
	char			buf[256];
	int				nbytes;
	std::string		request;
	struct pollfd	*socketArr;

	nbytes = 0;
	socketArr = _pfds.getSocketArr();
	while (1)
	{
		nbytes = recv(socketArr[i].fd, buf, 255, 0);
		if (nbytes == 0)
			break ;
		else if (nbytes < 0)
		{
			std::cout << "Recv error\n";
			close(socketArr[i].fd);
			_pfds.delFromPfds(i);
			std::cout << "Connection from " << socketArr[i].fd << " closed.\n";
			break ;
		}
		buf[nbytes] = '\0';
		request += buf;
		if (request.find("\r\n\r\n") != std::string::npos)
			break ;
	}
	std::cout << request << std::endl;
	this->parseRequest(request);
	// for (std::map<std::string, std::string>::iterator it = _requestMap.begin(); it != _requestMap.end(); it++)
	// 	std::cout << "first:" << it->first << " second:" << it->second << std::endl;
	Config location;
	if (this->checkRequest(socketArr[i].fd, location))
		handleRequest(socketArr[i].fd);
	_requestMap.clear();
	close(socketArr[i].fd);
	_pfds.delFromPfds(i);
}

void	Server::displayServerConfig(void) {
	std::cout << "Server" << std::endl;
	_config.displayConfig();
	for (sCMap::iterator it = _locationMap.begin(); it != _locationMap.end(); it++)
	{
		std::cout << "Name: " << it->first << std::endl;
		it->second.displayConfig();
	}
}

bool	Server::default_error_answer(int err, int fd) {
	sVec errpages = _config.getErrorPage();
	std::ifstream file;

	if (errpages.size() && err != 500) {
		std::stringstream temp;
		temp << err;
		std::string error = temp.str() + ".html";
		std::string	root = _config.getRoot() + "/";

		for (sVec::iterator it = errpages.begin(); it != errpages.end(); it++) {
			if ((*it) == error) {
				file.open(root + (*it));
				if (file.is_open())
					break ;
				file.close();
				return default_error_answer(500, fd);
			}

		}
	}

	std::string tmpString;


		switch (err)
	{
		case 100: tmpString = "100 Continue"; break ;
		case 200: tmpString = "200 OK"; break ;
		case 201: tmpString = "201 Created"; break ;
		case 202: tmpString = "202 Accepted"; break ;
		case 203: tmpString = "203 Non-Authoritative Information"; break ;
		case 204: tmpString = "204 No content"; break ;
		case 205: tmpString = "205 Reset Content"; break ;
		case 206: tmpString = "206 Partial Content"; break ;
		case 400: tmpString = "400 Bad Request"; break ;
		case 401: tmpString = "401 Unauthorized"; break ;
		case 402: tmpString = "402 Payment Required"; break ;
		case 403: tmpString = "403 Forbidden"; break ;
		case 404: tmpString = "404 Not Found"; break ;
		case 405: tmpString = "405 Method Not Allowed"; break ;
		case 406: tmpString = "406 Not Acceptable"; break ;
		case 411: tmpString = "411 Length Required"; break ;
		case 413: tmpString = "413 Request Entity Too Large"; break ;
		case 500: tmpString = "500 Internal Server Error"; break ;
		case 501: tmpString = "501 Not Implemented"; break ;
		case 510: tmpString = "510 Not Extended"; break ;
		default: break ;
	}

	std::stringstream convert;
	std::string res = "HTTP/1.1 " + tmpString + "\r\nServer: webserv1.0\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: ";

	if (file.is_open()) {
		convert << file.rdbuf();
		file.close();
		std::string body = convert.str();
		convert.str(std::string());
		convert << body.size();
		res.append(convert.str() + "\r\n\r\n" + body);
	}
	else if (err != 100) {
		std::string tmpBody = "<html><head><title>" + tmpString + "</title></head><body><p>" + tmpString + "</p></body></html>";
		//std::string res = "HTTP/1.1 " + tmpString + "\r\nAllow: POST\r\nServer: webserv1.0\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: 133";
		std::string defBody = "\r\n\r\n";
		defBody.append(tmpBody);
		res.append(defBody);
	}
	if (send(fd, res.c_str(), res.size(), 0) == -1)
		std::cout << "Send error!\n";
	return false;
}