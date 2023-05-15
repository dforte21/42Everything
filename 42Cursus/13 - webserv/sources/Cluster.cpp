#include "../includes/Cluster.hpp"

Cluster::Cluster(const char *filePath) {
	std::ifstream				configFile;
	std::string					fileContent;
	size_t						pos;
	std::vector<LocationConfig>	locationVec;

	if (filePath == NULL)
		filePath = "default.conf";
	configFile.open(filePath);
	if (!configFile.is_open())
		throw wrongFilePath();
	std::getline(configFile, fileContent, '\0');
	for(size_t pos = fileContent.find_first_of("#"); pos != std::string::npos; pos = fileContent.find_first_of("#"))
		fileContent.erase(pos, fileContent.find_first_of("\n", pos) - pos);
	this->divideByServer(fileContent);
	for(std::vector<std::string>::iterator it = _serverConfigVec.begin(); it != _serverConfigVec.end(); it++)
	{
		pos = (*it).find("location");
		if (pos == std::string::npos)
			throw badConfigFile();
		fileContent = (*it).substr(0, pos);
		Config	config(fileContent);
		fileContent = (*it).substr(pos, std::string::npos);
		_LocationConfigVec.clear();
		this->divideByLocation(fileContent);
		for(std::vector<std::string>::iterator it = _LocationConfigVec.begin(); it != _LocationConfigVec.end(); it++)
			locationVec.push_back(*it);
		_serverVec.push_back(Server(config, locationVec));
	}
}

Cluster::~Cluster(void) {

}

void	Cluster::divideByServer(std::string &fileContent) {
	size_t						bodyLen;

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
		_serverConfigVec.push_back(fileContent.substr(begin, bodyLen));
	}
}

void	Cluster::divideByLocation(std::string &fileContent) {
	size_t						end;

	for(size_t begin = fileContent.find("location"); begin != std::string::npos; begin = fileContent.find("location", end))
	{
		end = fileContent.find_first_of("}", begin);
		if (end == std::string::npos)
			throw badConfigFile();
		_LocationConfigVec.push_back(fileContent.substr(begin, end - begin));
	}
}

const char *Cluster::wrongFilePath::what() const throw() {
	return "Wrong file path";
}

const char *Cluster::badConfigFile::what() const throw() {
	return "Bad config file";
}