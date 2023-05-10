#include "../includes/Config.hpp"

Config::Config(std::string &configStr)
	: _configStr(configStr), _get(false), _post(false), _head(false), _put(false), _delete(false) {
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
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" ", pos + 6);
	if (pos >= end)
		throw badConfigFile();
	_listen = _configStr.substr(pos, end - pos);
	if(_listen.find_first_not_of("1234567890") != std::string::npos)
		throw badConfigFile();
}

void	Config::setServerName(void) {
	size_t	pos;
	size_t	end;
	std::string	line;

	pos = _configStr.find("server_name");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 11);
	if (pos >= end)
		throw badConfigFile();
	line = _configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		_server_name.push_back(line.substr(pos, end - pos));
	}
}

void	Config::setRoot(void) {
	size_t	pos;
	size_t	end;

	pos = _configStr.find("root");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 4);
	if (pos >= end)
		throw badConfigFile();
	_root = _configStr.substr(pos, end - pos);
	if (_root.find_first_of(" \t") != std::string::npos)
		throw badConfigFile();
}

void	Config::setIndex(void) {
	size_t	pos;
	size_t	end;
	std::string	line;

	pos = _configStr.find("index");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 5);
	if (pos >= end)
		throw badConfigFile();
	line = _configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		_index.push_back(line.substr(pos, end - pos));
	}
}

void	Config::setErrorPage(void) {
	size_t	pos;
	size_t	end;
	std::string	line;

	pos = _configStr.find("error_page");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 10);
	if (pos >= end)
		throw badConfigFile();
	line = _configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		_error_page.push_back(line.substr(pos, end - pos));
	}
}

void	Config::setClientMaxBodySize(void) {
	size_t	pos;
	size_t	end;
	std::string	line;

	pos = _configStr.find("client_max_body_size");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 20);
	if (pos >= end)
		throw badConfigFile();
	line = _configStr.substr(pos, end - pos);
	if (line.find_first_not_of("0123456789Kk") != std::string::npos)
		throw badConfigFile();
	pos = line.find_first_of("Kk");
	if (pos != std::string::npos)
		line.replace(pos, 1, 3, '0');
	_client_max_body_size = std::atoi(line.c_str());
}

void	Config::setAllowedMethods(void) {
	size_t	pos;
	size_t	end;
	std::string	line;
	std::string methods[5] = {"GET", "POST", "HEAD", "PUT", "DELETE"};
	int		i;

	pos = _configStr.find("allowed_methods");
	if (pos == std::string::npos)
		return ;
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" \t", pos + 15);
	if (pos >= end)
		throw badConfigFile();
	line = _configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		i = 0;
		while (i < 5)
		{
			if (line.substr(pos, end - pos) == methods[i])
				break ;
			i++;
		}
		switch(i) {
			case 0 :
				_get = true;
				break ;
			case 1 :
				_post = true;
				break ;
			case 2 :
				_head = true;
				break ;
			case 3 :
				_put = true;
				break ;
			case 4 :
				_delete = true;
				break ;
			default :
				throw badConfigFile();
		};
	}
}

const char *Config::badConfigFile::what() const throw() {
	return "Bad config file";
}