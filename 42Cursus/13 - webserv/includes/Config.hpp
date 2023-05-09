#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <vector>
# include <map>

class Config {
	private:
			std::string					_configStr;
			std::string					_listen;
			std::vector<std::string>	_server_name;
			std::string					_root;
			std::vector<std::string>	_index;
			std::vector<std::string>	_error_page;
			int							_client_max_body_size;
			bool	_get;
			bool	_post;
			bool	_delete;
			Config(void);

	public:
			Config(std::string &configStr);
			~Config(void);

			void	setListen(void);
			void	setServerName(void);
			void	setRoot(void);
			void	setIndex(void);
			void	setErrorPage(void);
			void	setClientMaxBodySize(void);
			void	setAllowedMethods(void);

			struct badConfigFile : public std::exception {
				virtual const char *what() const throw();
			};
};

#endif