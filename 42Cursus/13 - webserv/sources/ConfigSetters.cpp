#include "../includes/Config.hpp"

uint16_t	Config::setListen(std::string &configStr) {
	size_t		pos;
	size_t		end;
	int			myInt;
	std::string	line;

	pos = configStr.find("listen");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" ", pos + 6);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	if(line.find_first_not_of("1234567890") != std::string::npos)
		throw badConfigFile();
	myInt = std::stoi(line, 0, 10);
	if (myInt > static_cast<int>(UINT16_MAX) || myInt <= 0)
    	throw badConfigFile();
	return static_cast<uint16_t>(myInt);
}

sVec	Config::setServerName(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	sVec server_name;

	pos = configStr.find("server_name");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 11);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		server_name.push_back(line.substr(pos, end - pos));
	}
	return server_name;
}

std::string		Config::setRoot(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	root;

	pos = configStr.find("root");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 4);
	if (pos >= end)
		throw badConfigFile();
	root = configStr.substr(pos, end - pos);
	if (root.find_first_of(" \t") != std::string::npos)
		throw badConfigFile();
	return root;
}

sVec	Config::setIndex(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	sVec	index;


	pos = configStr.find("index");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 5);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		index.push_back(line.substr(pos, end - pos));
	}
	return index;
}

sVec	Config::setErrorPage(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	sVec	error_page;

	pos = configStr.find("error_page");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 10);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		error_page.push_back(line.substr(pos, end - pos));
	}
	return error_page;
}

int	Config::setClientMaxBodySize(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	int		myInt;

	pos = configStr.find("client_max_body_size");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 20);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	pos = line.find_first_of("Kk");
	if (pos != std::string::npos)
		line.replace(pos, 1, 3, '0');
	if (line.find_first_not_of("0123456789Kk") != std::string::npos)
		throw badConfigFile();
	myInt = std::stoi(line, 0, 10);
	if (myInt < 0)
		throw badConfigFile();
	return myInt;
}

std::map<std::string, bool>	Config::setAllowedMethods(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	std::map<std::string, bool>	allowed_methods;

	allowed_methods.insert(std::pair<std::string, bool>("GET", false));
	allowed_methods.insert(std::pair<std::string, bool>("POST", false));
	allowed_methods.insert(std::pair<std::string, bool>("HEAD", false));
	allowed_methods.insert(std::pair<std::string, bool>("PUT", false));
	allowed_methods.insert(std::pair<std::string, bool>("DELETE", false));
	pos = configStr.find("allowed_methods");
	if (pos == std::string::npos)
		return allowed_methods;
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 15);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		if(allowed_methods.find(line) == allowed_methods.end())
			throw badConfigFile();
		allowed_methods[line] = true;
	}
	return allowed_methods;
}
