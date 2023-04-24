#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "webserv.hpp"

class Config {
	public:
			Config() {};
			Config(char *filename);
			~Config() {};
	private:
			std::string _listen;
			std::string _server_name;
			std::string _root;
			std::string _index;
			std::string _error_page;
			std::string _client_max_body_size;
			std::string _allowed_methods;
} ;

#endif