#include "../includes/Server.hpp"

Server::Server() {
	std::cout << "server" << std::endl;
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
	int new_fd;
	struct sockaddr_storage client_addr;
	std::cout << "ciao\n";
	for (;;) {
		std::cout << "ciao1\n";
		socklen_t sin_size = sizeof(client_addr);
		new_fd = accept(_fd, (struct sockaddr *)&client_addr, &sin_size);
		std::cout << "Server is waiting...\n";
		if (!fork()){
			close (_fd);
			if (send(new_fd, "Hello, world!", 13, 0) == -1)
				std::cout << "Send error!\n";
			close (new_fd);
			exit (0);
		}
		close (new_fd);
	}
}

Server::~Server(){
	std::cout << "Addios\n";
}