#include "../includes/Server.hpp"

Server::Server(Config &config) {
	this->startListening();
}

Server::~Server(void) {

}

void	Server::startListening() {
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	fcntl(_fd, F_SETFL, O_NONBLOCK); //questo é il non bloccante
	if (_fd < 0)
		throw std::runtime_error("Unable to create socket");
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(8080); //probabilmente da cambiare
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int yes = 1;
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1)
		throw std::runtime_error("Unable to reuse port");
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
				if (i == 0) { //listener
					new_fd = accept(_fd, (struct sockaddr *)&client_addr, &sin_size);
					if (new_fd == -1)
                        throw std::runtime_error("Accept error");
					else {
						add_to_pfds(pfds, new_fd, &fd_count, &fd_size);
						printf("pollserver: new connection on socket %d\n", new_fd);
						if (send(new_fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
							std::cout << "Send error!\n";
					}
				}
				else { //client
					char buf[256];
					int nbytes = recv(pfds[i].fd, buf, sizeof buf, 0);

					if (nbytes == 0) {
					std::cout << "Connection from " << pfds[i].fd << " closed.\n";
					close(pfds[i].fd);
					del_from_pfds(pfds, i, &fd_count);
					}
					else if (nbytes < 0){
						std::cout << "Recv error\n";
						close(pfds[i].fd);
						del_from_pfds(pfds, i, &fd_count);
						std::cout << "Connection from " << pfds[i].fd << " closed.\n";
					}
					else {
							std::cout << "Ho ricevuto da socket " << pfds[i].fd <<buf<< std::endl;
						for(int j = 0; j < fd_count; j++) { 
							// Except the listener and ourselves
						if (pfds[j].fd != pfds[0].fd && pfds[j].fd != pfds[i].fd) {

							if (sendall(pfds[j].fd, buf, &nbytes) == -1)
									std::cout << "Send error!\n";
							}
						}
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

void	Server::add_to_pfds(struct pollfd *pfds, int new_fd, int *fd_count, int *fd_size){
	if (*fd_count == *fd_size){
		*fd_size *= 2;
		pfds = (struct pollfd *) realloc (pfds, sizeof(struct pollfd) * (*fd_size));
	}
	pfds[*fd_count].fd = new_fd;
	pfds[*fd_count].events = POLLIN;
	(*fd_count)++;
	//std::cout << "nuovo socket allocato, grandezza:" << *fd_size << " count: " << *fd_count << std::endl;
}

void	Server::del_from_pfds(struct pollfd *pfds,int i,int *fd_count){
	pfds[i] = pfds[*fd_count - 1];
	(*fd_count)--;
}

int Server::sendall(int fd,char *buf, int *len){
	int total = 0;
	int bytesleft = *len;
	int n;

	while(total < *len) {
		n = send(fd, buf+total, bytesleft, 0);
		if (n == -1)
			return -1;
		total += n;
		bytesleft -= n;
	}	
	*len = total;
	return 0;
}
