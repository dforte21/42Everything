#ifndef	CLUSTER_HPP
# define CLUSTER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include "Config.hpp"
# include "Server.hpp"
# include "Pfds.hpp"

typedef	std::map<std::string, Config> sCMap;

class Cluster {
	private:
		std::vector<Server>	_serverVec;
		int					_serverVecSize;
		/*std::vector<Pfds>	_PfdsVec;*/
		
		Cluster(void);

	public:
		Cluster(const char *filePath);
		~Cluster(void);

		sVec								divideByServer(std::string &fileContent);
		void								displayServerConfig(Config &config) const;

		void								setPfds(void);

		void								startListening(void);
		void								handleServer(Pfds &pfds);
		void								handleClient(Pfds &pfds, int i);

		void								handle_request(std::map<std::string, std::string> http_map, int fd);
		std::map<std::string, std::string>	parse_request(std::string request);

		struct	wrongFilePath : public std::exception {
			virtual const char *what() const throw();
		};

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
