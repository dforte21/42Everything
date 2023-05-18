#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <vector>
# include <map>
# include <cstdlib>

typedef	std::vector<std::string> sVec;
typedef	std::map<std::string, bool> sBMap;

class Config {
	friend class Server;

	private:
		std::string	_configStr;
		uint16_t	_listen;
		sVec		_server_name;
		std::string	_root;
		sVec		_index;
		sVec		_error_page;
		int			_client_max_body_size;
		sBMap		_allowed_methods;


	public:
		Config(void);
		Config(std::string &serverBody);
		~Config(void);

		std::string	findDirective(std::string &line) const;
		void		displayConfig(void) const;

		uint16_t	setListen(std::string &configStr);
		sVec		setServerName(std::string &configStr);
		std::string	setRoot(std::string &configStr);
		sVec		setIndex(std::string &configStr);
		sVec		setErrorPage(std::string &configStr);
		int			setClientMaxBodySize(std::string &configStr);
		sBMap		setAllowedMethods(std::string &configStr);


		std::string	getConfigStr(void) const;
		uint16_t	getListen(void) const;
		sVec		getServerName(void) const;
		std::string	getRoot(void) const;
		sVec		getIndex(void) const;
		sVec		getErrorPage(void) const;
		int			getClientMaxBodySize(void) const;
		sBMap		getAllowedMethods(void) const;

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
