#include "../includes/Config.hpp"

Config::Config(std::string &configStr) {
	//std::cout << configStr << std::endl;
}

Config::~Config(void) {
	
}

const char *Config::badConfigFile::what() const throw() {
	return "Bad config file";
}