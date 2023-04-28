#ifndef	CLUSTER_HPP
# define CLUSTER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Config.hpp"
#include "Server.hpp"

class Cluster {
	private:
		std::vector<Server> _serverVec;
		//std::vector<Config> _configVec;
		Cluster(void);

	public:
		Cluster(const char *filePath);
		~Cluster(void);

		struct	wrongFilePath : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif