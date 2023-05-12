#include "../includes/Config.hpp"

Config::Config(std::string &configStr)
	: _configStr(configStr) {
	//std::cout << configStr << std::endl;
	this->initAllowedMethods();
	this->setListen();
	this->setServerName();
	this->setRoot();
	this->setIndex();
	this->setErrorPage();
	this->setClientMaxBodySize();
	this->setAllowedMethods();
}

Config::~Config(void) {
	
}

void	Config::initAllowedMethods(void) {
	_allowed_methods.insert(std::pair<std::string, bool>("GET", false));
	_allowed_methods.insert(std::pair<std::string, bool>("POST", false));
	_allowed_methods.insert(std::pair<std::string, bool>("HEAD", false));
	_allowed_methods.insert(std::pair<std::string, bool>("PUT", false));
	_allowed_methods.insert(std::pair<std::string, bool>("DELETE", false));
}

void	Config::displayConfig(void) const {
	std::vector<std::string> vec;
	std::map<std::string, bool> map;

	std::cout << "listen: " << this->getListen() << std::endl;
	std::cout << "server_name: ";
	vec = this->getServerName();
	for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "root: " << this->getRoot() << std::endl;
	std::cout << "index: ";
	vec = this->getIndex();
	for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "error_page: ";
	vec = this->getErrorPage();
	for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "client_max_body_size: " << this->getClientMaxBodySize() << std::endl;
	std::cout << "allowed_methods: ";
	map = getAllowedMethods();
	std::cout << std::boolalpha;
	for(std::map<std::string, bool>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << '=' << it->second << ", ";
	std::cout << std::endl << std::endl;
}

const char *Config::badConfigFile::what() const throw() {
	return "Bad config file";
}