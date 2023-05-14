#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <vector>
# include <map>
# include <cstdlib>

class Config {
	private:
		std::string						_configStr;
		uint16_t						_listen;
		std::vector<std::string>		_server_name;
		std::string						_root;
		std::vector<std::string>		_index;
		std::vector<std::string>		_error_page;
		int								_client_max_body_size;
		std::map<std::string, bool>		_allowed_methods;
		bool							_autoindex;
		std::vector<std::string>		_try_files;
		std::string						_cgi_pass;
		std::vector<std::string>		_extension_cgi;

		Config(void);

	public:
		Config(std::string &configStr);
		~Config(void);

		void	displayConfig(void) const;

		uint16_t					setListen(std::string &configStr);
		std::vector<std::string>	setServerName(std::string &configStr);
		std::string					setRoot(std::string &configStr);
		std::vector<std::string>	setIndex(std::string &configStr);
		std::vector<std::string>	setErrorPage(std::string &configStr);
		int							setClientMaxBodySize(std::string &configStr);
		std::map<std::string, bool>	setAllowedMethods(std::string &configStr);
		bool						setAutoindex(std::string &configStr);
		std::vector<std::string>	setTryFiles(std::string &configStr);
		std::string					setCgiPass(std::string &configStr);
		std::vector<std::string>	setExtensionCgi(std::string &configStr);

		std::string					getConfigStr(void) const;
		uint16_t					getListen(void) const;
		std::vector<std::string>	getServerName(void) const;
		std::string					getRoot(void) const;
		std::vector<std::string>	getIndex(void) const;
		std::vector<std::string>	getErrorPage(void) const;
		int							getClientMaxBodySize(void) const;
		std::map<std::string, bool>	getAllowedMethods(void) const;
		bool						getAutoindex(void) const;
		std::vector<std::string>	getTryFiles(void) const;
		std::string					getCgiPass(void) const;
		std::vector<std::string>	getExtensionCgi(void) const;

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
