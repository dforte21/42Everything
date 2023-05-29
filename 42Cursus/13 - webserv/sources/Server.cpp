#include "../includes/Server.hpp"

Server::Server(Config &config) : _serverConfig(config) {
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
	//this->startListening();
}

Server::~Server(void) {

}

// void	Server::startListening() {
// 	int fd_count = 1;
//     int fd_size = 5;
// 	struct pollfd *pfds = (struct pollfd *)malloc(sizeof *pfds * fd_size);
// 	pfds[0].fd = _fd;
// 	pfds[0].events = POLLIN;
// 	int poll_count = 0;
// 	int new_fd;
// 	struct sockaddr_storage client_addr;
// 	socklen_t sin_size = sizeof(client_addr);
// 	for (;;) {
// 		poll_count = poll(pfds, fd_count, -1);
// 		if (poll_count == -1)
// 			throw std::runtime_error("Poll error");
// 		for(int i = 0; i < fd_count; i++) {
// 			if (pfds[i].revents & POLLIN) {
// 				if (i == 0) { //listener
// 					new_fd = accept(_fd, (struct sockaddr *)&client_addr, &sin_size);
// 					if (new_fd == -1)
//                         throw std::runtime_error("Accept error");
// 					else {
// 						add_to_pfds(pfds, new_fd, &fd_count, &fd_size);
// 						std::cout << "new_fd:" << new_fd << std::endl;
// 						// printf("pollserver: new connection on socket %d\n", new_fd);
// 						// if (send(new_fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
// 						// 	std::cout << "Send error!\n";
// 					}
// 				}
// 				else { //client
// 					char buf[1024];
// 					int nbytes = 0;
// 					std::string request;
// 					// if (nbytes > 0) {
// 					if ((nbytes = recv(pfds[i].fd, buf, 1024, 0)) <= 0) {
// 						// buf[nbytes] = 0;
// 						if (nbytes == 0) {
// 							std::cout << "Connection from " << pfds[i].fd << " closed.\n";
// 							close(pfds[i].fd);
// 							del_from_pfds(pfds, i, &fd_count);
// 						}
// 						else if (nbytes < 0){
// 							std::cout << "Recv error\n";
// 							close(pfds[i].fd);
// 							del_from_pfds(pfds, i, &fd_count);
// 							std::cout << "Connection from " << pfds[i].fd << " closed.\n";
// 							}
// 					}
// 					else {
// 						std::cout<< buf << "\nFINE"<<std::endl;
// 						std::string buffer(buf);
// 						request.append(buffer);
// 						// for(int j = 0; j < fd_count; j++) { 
// 						// 		// Except the listener and ourselves
// 						// 	if (pfds[j].fd != pfds[0].fd && pfds[j].fd != pfds[i].fd) {
// 						// 		if (sendall(pfds[j].fd, buf, &nbytes) == -1)
// 						// 				std::cout << "Send error!\n";
// 						// 		}
// 						// }
// 					}
// 					// std::cout<< "\n REQUEST:\n "<< request << std::endl;
// 					std::map<std::string, std::string> tok_http = this->parse_request(request);
// 					if (tok_http.empty() == true)
// 						std::cout<<"Mappa tokenizzata vuota!\n\n\n";
// 					// for (std::map<std::string, std::string>::iterator it = tok_http.begin();
// 					// 		it != tok_http.end(); it++) {
// 					// 			std::cout << "\nfirst:" << it->first << " second:" << it->second << std::endl;
// 					// }
// 					this->handle_request(tok_http, pfds[i].fd);
// 					close(pfds[i].fd);
// 					del_from_pfds(pfds, i, &fd_count);
// 				}
// 			}
// 		}
// 	}
// }

void	Server::default_error_answer(int err, int fd) {
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

	if (err != 100) {
		std::string tmpBody = "<html><head><title>" + tmpString + "</title></head><body><p>" + tmpString + "</p></body></html>";
		std::string res = "HTTP/1.1 " + tmpString + "\r\nAllow: POST\r\nServer: webserv1.0\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: 133";
		std::string defBody = "\r\n\r\n";
		defBody.append(tmpBody);
		res.append(defBody);
		if (send(fd, res.c_str(), res.size(), 0) == -1)
			std::cout << "Send error!\n";
	}
}

// void Server::handle_request(std::map<std::string, std::string> http_map, int fd) {
// 	if (http_map.empty())
// 		return ;
// 	std::map<std::string, bool>::iterator it = _serverConfig.getAllowedMethods().find(http_map.at("HTTP_method"));
// 	if (it == _serverConfig.getAllowedMethods().end() || it->second == false)
// 		this->default_error_answer(405, fd);
// 	else
// 		if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, 0) == -1)
// 							std::cout << "Send error!\n";
		
// }

// std::map<std::string, std::string> Server::parse_request(std::string request) {
// 	std::size_t first = 0;
// 	std::size_t find = 0;
// 	std::size_t i = 0;

// 	const char *prova = request.c_str();
// 	std::map<std::string, std::string> map;
// 	std::string line;

// 	while (prova[i] != '\0') {
// 		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
// 			line = request.substr(first, i - first);
// 			// std::cout << "firstline: " << line << std::endl;
// 			std::size_t space = line.find(' ', 0);
// 			std::size_t space2 = line.find(' ', space + 1);
// 			map.insert(std::pair<std::string, std::string>("HTTP_method", line.substr(0, space)));
// 			map.insert(std::pair<std::string, std::string>("URL", line.substr(space + 1, space2 - space)));
// 			map.insert(std::pair<std::string, std::string>("protocol_version", line.substr(space2 + 1, line.length())));
// 			if (prova[i] != 4)
// 				i++;
// 			first = i + 1;
// 			break ;
// 		}
// 		i++;
// 	}
// 	while (prova[i] != '\0') {
// 		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
// 			line = request.substr(first, i - first);
// 			if (prova[i] != 4)
// 				i++;
// 			first = i + 1;
// 		std::size_t mid = line.find(':', 0);
// 		if (mid != std::string::npos && line[mid] == ':' && line[mid + 1] == ' ')
// 			map.insert(std::pair<std::string, std::string>(line.substr(0, mid), line.substr(mid + 2 , line.length())));
// 		else
// 			map.insert(std::pair<std::string, std::string>(line.substr(0, line.length()), ""));
// 		}
// 		i++;
// 	}
// 	return map;
// }
