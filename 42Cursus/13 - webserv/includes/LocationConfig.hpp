#ifndef LOCATIONCONFIG_HPP
# define LOCATIONCONFIG_HPP

# include "Config.hpp"

class	LocationConfig : public Config {
	private:
		std::string					_locationName;
		bool						_autoindex;
		std::vector<std::string>	_try_files;
		std::string					_cgi_pass;
		std::vector<std::string>	_extension_cgi;

		LocationConfig(void);

	public:
		LocationConfig(std::string &ConfigStr);
		~LocationConfig(void);

		bool						setAutoindex(std::string &configStr);
		std::vector<std::string>	setTryFiles(std::string &configStr);
		std::string					setCgiPass(std::string &configStr);
		std::vector<std::string>	setExtensionCgi(std::string &configStr);

		bool						getAutoindex(void) const;
		std::vector<std::string>	getTryFiles(void) const;
		std::string					getCgiPass(void) const;
		std::vector<std::string>	getExtensionCgi(void) const;
};

#endif