#include "../includes/Config.hpp"

void	Config::setListen(void) {
	size_t		pos;
	size_t		end;
	std::string	listen_str;

	pos = _configStr.find("listen");
	end = _configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || _configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = _configStr.find_first_not_of(" ", pos + 6);
	if (pos >= end)
		throw badConfigFile();
	listen_str = _configStr.substr(pos, end - pos);
	int	myInt(std::stoi(listen_str));
	if (myInt <= static_cast<int>(UINT16_MAX) && myInt >=0)
    	_listen = static_cast<uint16_t>(myInt);
	else
		std::cout << "PORT OUT OF RANGE (uint16_t)\n";
	if(listen_str.find_first_not_of("1234567890") != std::string::npos)
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
		if(_allowed_methods.find(line) == _allowed_methods.end())
			throw badConfigFile();
		_allowed_methods[line] = true;
	}
}
