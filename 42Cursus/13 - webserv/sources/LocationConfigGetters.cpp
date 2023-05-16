#include "../includes/LocationConfig.hpp"

bool	LocationConfig::getAutoindex(void) const {
	return _autoindex;
}

std::vector<std::string>	LocationConfig::getTryFiles(void) const {
	return _try_files;
}

std::string	LocationConfig::getCgiPass(void) const {
	return _cgi_pass;
}

std::vector<std::string>	LocationConfig::getExtensionCgi(void) const {
	return _extension_cgi;
}