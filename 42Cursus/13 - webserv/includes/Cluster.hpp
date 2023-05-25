#ifndef	CLUSTER_HPP
# define CLUSTER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include "Config.hpp"
# include "Server.hpp"

typedef	std::map<std::string, Config> sCMap;

class Cluster {
	private:
		std::vector<Server>	_serverVec;
		int					_serverVecSize;
		struct pollfd 		**_pfds;
		
		Cluster(void);

	public:
		Cluster(const char *filePath);
		~Cluster(void);

		sVec								divideByServer(std::string &fileContent);
		void								displayServerConfig(Config &config) const;
		void								setPfds(void);
		void								startListening(void);
		void								handle_request(std::map<std::string, std::string> http_map, int fd);
		std::map<std::string, std::string>	parse_request(std::string request);
		void								add_to_pfds(struct pollfd *pfds, int new_fd, int *fd_count, int *fd_size);
		void								del_from_pfds(struct pollfd *pfds,int i,int *fd_count);
		struct	wrongFilePath : public std::exception {
			virtual const char *what() const throw();
		};

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif


13 3
