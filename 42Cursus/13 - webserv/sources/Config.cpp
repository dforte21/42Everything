#include "../includes/Config.hpp"

Config::Config() {

}

Config::Config(std::string &serverBody) {
	//std::cout << serverBody << std::endl;
}

Config::~Config(void) {
	
}

// std::string	Config::findDirective(std::string &line) const {
// 	size_t	pos;

	
// }

void	Config::displayConfig(void) const {
	sVec vec;
	std::map<std::string, bool> map;

	std::cout << "listen: " << this->getListen() << std::endl;
	std::cout << "server_name: ";
	vec = this->getServerName();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "root: " << this->getRoot() << std::endl;
	std::cout << "index: ";
	vec = this->getIndex();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "error_page: ";
	vec = this->getErrorPage();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
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
