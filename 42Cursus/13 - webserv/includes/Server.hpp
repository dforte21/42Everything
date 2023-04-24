#ifndef SERVER_HPP
#define SERVER_HPP

#include "webserv.hpp"

class Server {
	public:
		Server();
		~Server();

	private:
		void	startListening();
		int					_fd;
		struct	sockaddr_in _addr;
};

#endif