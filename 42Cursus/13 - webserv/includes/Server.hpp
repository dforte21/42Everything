#ifndef SERVER_HPP
# define SERVER_HPP

# include "Config.hpp"
#include "Pfds.hpp"
# include <iostream>
# include <netinet/in.h>
# include "unistd.h"
# include <poll.h>
# include <fcntl.h>
# include <vector>

class Server {
	private:
		int							_fd;
		struct	sockaddr_in 		_addr;
		Config						_serverConfig;

		Server();

		void	default_error_answer(int err, int fd);
		int		createListenSocket(void);

	public:
		Pfds						_pollfd;

		Server(Config &config);
		~Server();
		
		int		getServerSocket(void) const;
};

#endif