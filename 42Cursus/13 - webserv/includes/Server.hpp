#ifndef SERVER_HPP
#define SERVER_HPP


class Server {
	public:
		Server();
	private:
		int					_fd;
		struct	sockaddr_in _addr;
};

#endif