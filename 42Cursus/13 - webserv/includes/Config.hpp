#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <iostream>

class Config {
	private:
			std::string _listen;
			std::string _server_name;
			std::string _root;
			std::string _index;
			std::string _error_page;
			std::string _client_max_body_size;
			std::string _allowed_methods;
			Config(void);

	public:
			Config(std::string str);
			~Config(void);
};

#endif