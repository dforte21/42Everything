#ifndef SERVER_HPP
# define SERVER_HPP

#include "Config.hpp"
#include <iostream>
#include <netinet/in.h>
#include "unistd.h"
#include <poll.h>
#include <fcntl.h>
#include <map>

class Server {
	private:
		int					_fd;
		struct	sockaddr_in _addr;
		Config				_config;

		Server();

		void								startListening();
		std::map<std::string, std::string>	parse_request(std::string request);
		void								handle_request(std::map<std::string, std::string>, int fd);
		void								add_to_pfds(struct pollfd *pfds, int new_fd, int *fd_count, int *fd_size);
		void								del_from_pfds(struct pollfd *, int i, int *fd_count);
		int									sendall(int fd,char *buf, int *len);
	public:
		Server(Config &config);
		~Server();
};

#endif