#include "../includes/Config.hpp"

Config::Config(char *filename){
	std::ifstream	configFile(filename);
	std::string		line;

	if (!configFile.is_open())
		exit(1);
	//while (getline(configFile, line)){
	//	std::cout<< line << std::endl;
	//}
	//else
	//	die("Error opening file. Aborting");
}