#include "../includes/Cluster.hpp"

Cluster::Cluster() {

}

Cluster::Cluster(const char *filePath){
	std::ifstream		configFile;
	std::string			line;
	std::stringstream	serverConfig;

	if (filePath == NULL)
		configFile.open("default.conf");
	else
		configFile.open(filePath);
	if (!configFile.is_open())
		throw wrongFilePath();
	std::getline(configFile, line);
	while (!configFile.eof()) {
		if (line.find("server {") != std::string::npos) {
			while (std::getline(configFile, line)) {
				if (line.find("server {") != std::string::npos)
					break ;
				serverConfig << line << std::endl;
			}
			Config config(serverConfig.str());
			_serverVec.push_back(config);
			serverConfig.str("");
		}
		else
			std::getline(configFile, line);
	}
}

Cluster::~Cluster(void) {

}

const char *Cluster::wrongFilePath::what() const throw() {
	return "Wrong file path";
}