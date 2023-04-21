#pragma once

#include <iostream>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/types.h>
//#include <sys/event.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

class Server {
	public:
		Server();
		~Server();
		int					_fd;
	private:
		struct	sockaddr_in _addr;
};
