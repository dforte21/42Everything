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
		std::vector<Config>	_configVec;
		std::vector<Server>	_serverVec;
		struct pollfd 		*_pfds;
		int					_pfdsSize;
		
		Cluster(void);

	public:
		Cluster(const char *filePath);
		~Cluster(void);

		sVec	divideByServer(std::string &fileContent);
		void	displayServerConfig(Config &config) const;
		void	setPfds(void);
		void	startListening(void);

		struct	wrongFilePath : public std::exception {
			virtual const char *what() const throw();
		};

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif