#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <vector>
# include <map>
# include <cstdlib>
# include <utility>

typedef	std::vector<std::string> sVec;
typedef	std::map<std::string, bool> sBMap;
typedef	std::pair<int, std::string> iSPair;

class Config {
	typedef	std::map<std::string, Config> sCMap;

	private:
		uint16_t	_listen;
		sVec		_server_name;
		std::string	_root;
		sVec		_index;
		sVec		_error_page;
		int			_client_max_body_size;
		sBMap		_allowed_methods;
		bool		_autoindex;
		sVec		_try_files;
		std::string	_cgi_pass;
		sVec		_extension_cgi;
		iSPair		_return;

		sCMap		_locationMap;

	public:
		Config(void);
		Config(std::string &serverBody);
		Config	&operator=(Config &rhs);
		~Config(void);

		int			doDirective(std::string &line);
		void		addLocation(std::string &serverBody);
		void		displayConfig(void) const;

		uint16_t	setListen(std::string &configStr);
		sVec		setServerName(std::string &configStr);
		std::string	setRoot(std::string &configStr);
		sVec		setIndex(std::string &configStr);
		sVec		setErrorPage(std::string &configStr);
		int			setClientMaxBodySize(std::string &configStr);
		sBMap		setAllowedMethods(std::string &configStr);
		bool		setAutoindex(std::string &configStr);
		sVec		setTryFiles(std::string &configStr);
		std::string	setCgiPass(std::string &configStr);
		sVec		setExtensionCgi(std::string &configStr);
		iSPair		setReturn(std::string &configStr);

		uint16_t	getListen(void) const;
		sVec		getServerName(void) const;
		std::string	getRoot(void) const;
		sVec		getIndex(void) const;
		sVec		getErrorPage(void) const;
		int			getClientMaxBodySize(void) const;
		sBMap		getAllowedMethods(void) const;
		bool		getAutoindex(void) const;
		sVec		getTryFiles(void) const;
		std::string	getCgiPass(void) const;
		sVec		getExtensionCgi(void) const;
		iSPair		getReturn(void) const;
		sCMap		getLocationMap(void) const;

		struct badConfigFile : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
