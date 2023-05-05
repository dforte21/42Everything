#include "../includes/Cluster.hpp"

Cluster::Cluster() {

}

Cluster::Cluster(const char *filePath) {
	std::ifstream	configFile;
	std::string		fileContent;

	if (filePath == NULL)
		filePath = "default.conf";
	configFile.open(filePath);
	if (!configFile.is_open())
		throw wrongFilePath();
	std::getline(configFile, fileContent, '\0');
	//std::cout << fileContent << std::endl;
	//this->setConfigVec(fileContent);
	// for(std::vector<Config>::iterator it = _configVec.begin(); it != _configVec.end(); it++)
	// 	_serverVec.push_back(*it);
	Config config(filePath);
	Server server(config);
}

Cluster::~Cluster(void) {

}

void	Cluster::setConfigVec(std::string &fileContent) {
	size_t						bodyLen;
	std::vector<std::string>	serverConfig;

	if (fileContent.find_first_not_of(" ") < fileContent.find("server"))
		throw badConfigFile();
	for (int begin = fileContent.find_first_of("{"); begin != std::string::npos; begin = fileContent.find_first_of("{", begin + bodyLen))
	{
		bodyLen = 0;
		for (int bracketsCount = 0; begin + bodyLen < fileContent.length(); bodyLen++)
		{
			if (fileContent.at(begin + bodyLen) == '{')
				bracketsCount++;
			else if (fileContent.at(begin + bodyLen) == '}')
				bracketsCount--;
			if (bracketsCount == 0)
				break ;
		}
		if (begin + bodyLen >= fileContent.length())
			throw badConfigFile();
		serverConfig.push_back(fileContent.substr(begin + 1, bodyLen - 1));
	}
	for (std::vector<std::string>::iterator it = serverConfig.begin(); it != serverConfig.end(); it++)
		_configVec.push_back(*it);
}

const char *Cluster::wrongFilePath::what() const throw() {
	return "Wrong file path";
}

const char *Cluster::badConfigFile::what() const throw() {
	return "Bad config file";
}