#include "../includes/Server.hpp"
#include <sstream>

Server::Server(Config &config) : _config(config){
	config.displayConfig();
	// _config = config;
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	fcntl(_fd, F_SETFL, O_NONBLOCK); //questo é il non bloccante
	if (_fd < 0)
		throw std::runtime_error("Unable to create socket");
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(config.getListen()); //probabilmente da cambiare
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int yes = 1;
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1)
		throw std::runtime_error("Unable to reuse port");
	if (bind(_fd,(struct sockaddr *)&_addr, sizeof(_addr)) < 0)
		throw std::runtime_error("Unable to bind socket");
	if (listen(_fd, 1000) < 0)
		throw std::runtime_error("Listen error");
	this->startListening();
}

Server::~Server(void) {

}

void	Server::startListening() {
	int fd_count = 1;
    int fd_size = 5;
	struct pollfd *pfds = (struct pollfd *)malloc(sizeof *pfds * fd_size);
	pfds[0].fd = _fd;
	pfds[0].events = POLLIN;
	int poll_count = 0;
	int new_fd;
	struct sockaddr_storage client_addr;
	socklen_t sin_size = sizeof(client_addr);
	for (;;) {
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
						std::cout << "new_fd:" << new_fd << std::endl;
						// printf("pollserver: new connection on socket %d\n", new_fd);
						// if (send(new_fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
						// 	std::cout << "Send error!\n";
					}
				}
				else { //client
					char buf[1024];
					int nbytes = 0;
					std::string request;
					// if (nbytes > 0) {
						if ((nbytes = recv(pfds[i].fd, buf, 1024, 0)) <= 0) {
						// buf[nbytes] = 0;
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
						}
						else {
							std::cout<< buf << "\nFINE"<<std::endl;
							std::string buffer(buf);
							request.append(buffer);
							// for(int j = 0; j < fd_count; j++) { 
							// 		// Except the listener and ourselves
							// 	if (pfds[j].fd != pfds[0].fd && pfds[j].fd != pfds[i].fd) {

							// 		if (sendall(pfds[j].fd, buf, &nbytes) == -1)
							// 				std::cout << "Send error!\n";
							// 		}
							// }
					}
					// std::cout<< "\n REQUEST:\n "<< request << std::endl;
					std::map<std::string, std::string> tok_http = this->parse_request(request);
					if (tok_http.empty() == true)
						std::cout<<"Mappa tokenizzata vuota!\n\n\n";
					// for (std::map<std::string, std::string>::iterator it = tok_http.begin();
					// 		it != tok_http.end(); it++) {
					// 			std::cout << "\nfirst:" << it->first << " second:" << it->second << std::endl;
					// }
					this->handle_request(tok_http, pfds[i].fd);
					close(pfds[i].fd);
					del_from_pfds(pfds, i, &fd_count);
				}
			}
		}
	}
}

void Server::handle_request(std::map<std::string, std::string> http_map, int fd) {
	std::map<std::string, bool>::iterator it = _config._allowed_methods.find(http_map.at("HTTP_method"));
	std::cout << "fd:" << fd << std::endl;
	if (it == _config._allowed_methods.end() || it->second == false) {
		// std::cout<<"Dentro false!\n";
		std::string tmpBody = "<html><head><title>Operation Not Permitted</title></head><body><p>This resource is read-only and cannot be deleted.</p></body></html>";
		std::string res = "HTTP/1.1 405 Method Not Allowed\r\nAllow: POST\r\nServer: webserv1.0\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: ";
		std::stringstream ss;
		ss << tmpBody.size();
		res.append(ss.str());
		std::string defBody = "\r\n\r\n";
		defBody.append(tmpBody);
		// res.append("\r\n\r\n");
		res.append(defBody);
		std::cout<< "res:\n" << res ;
		if (send(fd, res.c_str(), res.size(), 0) == -1)
			std::cout << "Send error!\n";
	}
	else
		if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
							std::cout << "Send error!\n";
		
}

std::map<std::string, std::string> Server::parse_request(std::string request) {
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
