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

typedef std::map<std::string, Config> sCMap;

class Server {
	private:
		Pfds	_pfds;
		Config	_config;
		sCMap	_locationMap;

		Server();

		void	default_error_answer(int err, int fd);
		void	handleGET(std::map<std::string, std::string> http_map, int fd);

	public:
		Server(Config &config, sCMap &locationMap);
		~Server();
		
		void	startListening(void);
		void	handleServer(void);
		void	handleClient(int i);
		std::map<std::string, std::string>	parseRequest(std::string request);
		void								handleRequest(std::map<std::string, std::string> http_map, int fd);
		void	displayServerConfig(void);
};

#endif