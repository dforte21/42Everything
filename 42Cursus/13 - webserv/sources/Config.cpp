#include "../includes/Config.hpp"

Config::Config(std::string &configStr) {
	_listen = this->setListen(configStr);
	_server_name = this->setServerName(configStr);
	_root = this->setRoot(configStr);
	_index = this->setIndex(configStr);
	_error_page = this->setErrorPage(configStr);
	_client_max_body_size = this->setClientMaxBodySize(configStr);
	_allowed_methods = this->setAllowedMethods(configStr);
	this->displayConfig();
}

Config::~Config(void) {
	
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
