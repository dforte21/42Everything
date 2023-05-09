#include "../includes/Config.hpp"

Config::Config(std::string &configStr)
	: _configStr(configStr), _get(false), _post(false), _delete(false) {
	this->setListen();
	this->setServerName();
	this->setRoot();
	this->setIndex();
	this->setErrorPage();
	this->setClientMaxBodySize();
	this->setAllowedMethods();
	//std::cout << configStr << std::endl;
}

Config::~Config(void) {
	
}

void	Config::setListen(void) {
		size_t	pos;
		size_t	end;

		pos = _configStr.find("listen");
		end = _configStr.find(";", pos);
		if (pos == std::string::npos || end == std::string::npos)
			throw badConfigFile();
		pos = _configStr.find_first_not_of(" ", pos + 6);
		if (pos >= end)
			throw badConfigFile();
		_listen = _configStr.substr(pos, end - pos);
		if(_listen.find_first_not_of("1234567890") != std::string::npos)
			throw badConfigFile();
		std::cout << _listen << std::endl;
}

void	Config::setServerName(void) {
	
}

void	Config::setRoot(void) {
	
}

void	Config::setIndex(void) {
	
}

void	Config::setErrorPage(void) {
	
}

void	Config::setClientMaxBodySize(void) {
	
}

void	Config::setAllowedMethods(void) {
	
}

const char *Config::badConfigFile::what() const throw() {
	return "Bad config file";
}