#ifndef SERVER_HPP
#define SERVER_HPP

#include "webserv.hpp"

class Server {
	public:
		Server();
		~Server();

		

	private:
		void	startListening();
		void	add_to_pfds(struct pollfd *pfds, int new_fd, int *fd_count, int *fd_size);
		void	del_from_pfds(struct pollfd *pfds,int i,int *fd_count);
		int					_fd;
		struct	sockaddr_in _addr;
};

#endif