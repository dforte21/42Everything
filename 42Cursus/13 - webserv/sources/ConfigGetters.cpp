#include "../includes/Config.hpp"

std::string	Config::getConfigStr(void) const {
	return _configStr;
}

uint16_t	Config::getListen(void) const {
	return _listen;
}

sVec		Config::getServerName(void) const {
	return _server_name;
}

std::string	Config::getRoot(void) const {
	return _root;
}

sVec		Config::getIndex(void) const {
	return _index;
}

sVec		Config::getErrorPage(void) const {
	return _error_page;
}

int			Config::getClientMaxBodySize(void) const {
	return _client_max_body_size;
}

sBMap		Config::getAllowedMethods(void) const {
	return _allowed_methods;
}
