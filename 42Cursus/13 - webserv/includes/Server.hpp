#ifndef SERVER_HPP
# define SERVER_HPP

# include "Config.hpp"
# include "Pfds.hpp"
# include <iostream>
# include <netinet/in.h>
# include "unistd.h"
# include <poll.h>
# include <fcntl.h>
# include <vector>
# include <fstream>
# include <string>
# include <sstream>
# include <sys/stat.h>

typedef std::map<std::string, Config>		sCMap;
typedef std::map<std::string, std::string>	sSMap;

typedef	enum {
	GET,
	POST,
	DELETE,
	HEAD,
	PUT,
	ERROR,
}	requests;

class Server {
	private:
		Pfds	_pfds;
		Config	_config;
		sCMap	_locationMap;
		sSMap	_requestMap;

		Server();

		void	handleServer(void);
		void	handleClient(int i);
		bool	checkRequest(int fd, Config &location);
		void	parseRequest(std::string request);
		void	handleRequest(int fd, Config &location);
		void	handleGET(int fd, Config &location);
		void	handleDELETE(int fd);
		void	handlePUT(int fd, Config &location);
		void	handleChunked(int fd,Config &location);
		size_t	getHexSize_E_Content(std::string &line, std::stringstream &content);
		void	handlePOST(int fd, Config &location);
		int		getBody(std::ifstream &body, Config &location);
		bool	getIcon(std::ifstream &body);
		bool	checkTryFiles(std::string check, Config &location);
		bool	checkExtensionCgi(std::string end, Config &location);
		void	default_error_answer(int err, int fd, Config &location);

	public:
		Server(Config &config, sCMap &locationMap);
		~Server();
		
		void	startListening(void);
		void	displayServerConfig(void);
	
};
		
	bool	isDirectory(const std::string& path);

#endif