#ifndef	CLUSTER_HPP
# define CLUSTER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include "Config.hpp"
# include "LocationConfig.hpp"
# include "Server.hpp"

class Cluster {
	private:
		std::vector<Config>	_configVec;
		std::vector<Server>	_serverVec;
		
		Cluster(void);

	public:
		Cluster(const char *filePath);
		~Cluster(void);

		sVec	divideByServer(std::string &fileContent);

		struct	wrongFilePath : public std::exception {
			virtual const char *what() const throw();
		};

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif