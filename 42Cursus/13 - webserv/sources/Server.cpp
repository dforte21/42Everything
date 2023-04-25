#include "../includes/Server.hpp"

Server::Server() {
	
	this->startListening();
}

void	Server::startListening() {
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	//fcntl(_fd, F_SETFL, O_NONBLOCK); //questo é il non bloccante
	if (_fd < 0)
		throw std::runtime_error("Unable to create socket");
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(8080); //probabilmente da cambiare
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_fd,(struct sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("Unable to bind socket");
	if (listen(_fd, 1000) < 0)
		throw std::runtime_error("Listen error");

	int fd_count = 1;
    int fd_size = 5;
	struct pollfd *pfds = (struct pollfd *)malloc(sizeof *pfds * fd_size);
	pfds[0].fd = _fd;
	pfds[0].events = POLLIN;
	int poll_count = 0;
	int new_fd;
	struct sockaddr_storage client_addr;
	socklen_t sin_size = sizeof(client_addr);
	while (1) {
		poll_count = poll(pfds, fd_count, -1);
		if (poll_count == -1)
			throw std::runtime_error("Poll error");
		 for(int i = 0; i < fd_count; i++) {
			if (pfds[i].revents & POLLIN) {
				if (i == 0) {
					
					new_fd = accept(_fd, (struct sockaddr *)&client_addr, &sin_size);
					if (new_fd == -1)
                        throw std::runtime_error("Accept error");
					else {
						//add_to_pfds();
						printf("pollserver: new connection on socket %d\n", new_fd);
					}
				}
			}
		}
	}

	//int new_fd;
	//struct sockaddr_storage client_addr;
	//while (1) {
	//	socklen_t sin_size = sizeof(client_addr);
	//	std::cout << "Server is waiting...\n";
	//	new_fd = accept(_fd, (struct sockaddr *)&client_addr, &sin_size);
	//	if (!fork()){
	//		close (_fd);
	//		if (send(new_fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
	//			std::cout << "Send error!\n";
	//		close (new_fd);
	//		exit (0);
	//	}
	//	close (new_fd);
	//}
}

Server::~Server(){
	std::cout << "Addios\n";
}