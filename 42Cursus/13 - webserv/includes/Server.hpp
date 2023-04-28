#ifndef SERVER_HPP
# define SERVER_HPP

#include "Config.hpp"
#include <iostream>
#include <netinet/in.h>
#include "unistd.h"
#include <poll.h>
#include <fcntl.h>

class Server {
	private:
		int					_fd;
		struct	sockaddr_in _addr;

		Server();

		void	startListening();
		void	add_to_pfds(struct pollfd *pfds, int new_fd, int *fd_count, int *fd_size);
		void	del_from_pfds(struct pollfd *, int i, int *fd_count);
	public:
		Server(Config &config);
		~Server();
};

#endif