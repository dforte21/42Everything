#include "../includes/webserv.hpp"
#include "../includes/Server.hpp"

Server::Server() {
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0)
		throw std::runtime_error("Unable to create socket");
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(8080); //probabilmente da cambiare
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_fd,(struct sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("Unable to bind socket");
	if (listen(_fd, 1000) < 0)
		throw std::runtime_error("Listen error");
}