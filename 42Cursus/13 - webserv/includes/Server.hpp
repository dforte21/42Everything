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
# include <fstream>
# include <string>
# include <sstream>

typedef std::map<std::string, Config>		sCMap;
typedef std::map<std::string, std::string>	sSMap;

class Server {
	private:
		Pfds	_pfds;
		Config	_config;
		sCMap	_locationMap;
		sSMap	_requestMap;

		Server();

	public:
		Server(Config &config, sCMap &locationMap);
		~Server();
		
		void	startListening(void);
		void	handleServer(void);
		void	handleClient(int i);
		
		void	displayServerConfig(void);
	
		bool	checkRequest(int fd, Config &location);
		void	parseRequest(std::string request);
		void	handleRequest(int fd);
		void	handleGET(int fd);
		void	handleDELETE(int fd);
		bool	getBody(std::ifstream &body, int fd);
		
		bool	default_error_answer(int err, int fd);
};

#endif