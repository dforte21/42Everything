#include "../includes/Cluster.hpp"

Cluster::Cluster(const char *filePath) {
	std::ifstream	configFile;
	std::string		fileContent;

	if (filePath == NULL)
		filePath = "default.conf";
	configFile.open(filePath);
	if (!configFile.is_open())
		throw wrongFilePath();
	std::getline(configFile, fileContent, '\0');
	this->setConfigVec(fileContent);
	for(std::vector<Config>::iterator it = _configVec.begin(); it != _configVec.end(); it++)
		_serverVec.push_back(*it);
	// std::string path(filePath);
	// Config config(path);
	// Server server(config);
}

Cluster::~Cluster(void) {

}

void	Cluster::setConfigVec(std::string &fileContent) {
	size_t						bodyLen;
	std::vector<std::string>	serverConfig;

	if (fileContent.find_first_not_of(" \n") < fileContent.find("server"))
		throw badConfigFile();
	else if (fileContent.find_first_not_of(" \n", (fileContent.find("server") + 6)) < fileContent.find_first_of("{"))
		throw badConfigFile();
	for (int begin = fileContent.find_first_of("{"); begin != std::string::npos; begin = fileContent.find_first_of("{", begin + bodyLen))
	{
		bodyLen = 0;
		for (int bracketsCount = 0; begin + bodyLen < fileContent.length();)
		{
			if (fileContent.at(begin + bodyLen) == '{')
				bracketsCount++;
			else if (fileContent.at(begin + bodyLen) == '}')
				bracketsCount--;
			bodyLen++;
			if (bracketsCount == 0)
				break ;
		}
		if (fileContent.at(begin + bodyLen - 1) != '}')
			throw badConfigFile();
		if (fileContent.find_first_not_of(" \n", begin + bodyLen) < fileContent.find("server", begin + bodyLen))
		 	throw badConfigFile();
		if (fileContent.find("server", begin + bodyLen) != std::string::npos &&
			fileContent.find_first_not_of(" \n", fileContent.find("server", begin + bodyLen) + 6) < fileContent.find_first_of("{", begin + bodyLen))
				throw badConfigFile();
		serverConfig.push_back(fileContent.substr(begin, bodyLen));
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