#include "../includes/LocationConfig.hpp"

bool	LocationConfig::setAutoindex(std::string &configStr) {
	size_t		pos;
	size_t		end;
	std::string	line;
	std::string	mode[2] = {"on", "off"};
	int			i;

	pos = configStr.find("autoindex");
	if (pos == std::string::npos)
		return false;
	end = configStr.find(";", pos);
	if (end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 9);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (i = 0; i < 2; i++)
		if (line == mode[i])
			break ;
	switch(i) {
		case 0 :
			return true;
		case 1 :
			return false;
		default :
			throw badConfigFile();
	};
}

std::vector<std::string>	LocationConfig::setTryFiles(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	std::vector<std::string>	try_files;

	pos = configStr.find("try_files");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 9);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		try_files.push_back(line.substr(pos, end - pos));
	}
	return try_files;
}

std::string		LocationConfig::setCgiPass(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	cgi_pass;

	pos = configStr.find("cgi_pass");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 4);
	if (pos >= end)
		throw badConfigFile();
	cgi_pass = configStr.substr(pos, end - pos);
	if (cgi_pass.find_first_of(" \t") != std::string::npos)
		throw badConfigFile();
	return cgi_pass;
}

std::vector<std::string>	LocationConfig::setExtensionCgi(std::string &configStr) {
	size_t	pos;
	size_t	end;
	std::string	line;
	std::vector<std::string>	extension_cgi;

	pos = configStr.find("extension_cgi");
	end = configStr.find(";", pos);
	if (pos == std::string::npos || end == std::string::npos || configStr.at(end + 1) != '\n')
		throw badConfigFile();
	pos = configStr.find_first_not_of(" \t", pos + 9);
	if (pos >= end)
		throw badConfigFile();
	line = configStr.substr(pos, end - pos);
	for (pos = 0; pos != std::string::npos; pos = line.find_first_not_of(" \t", end))
	{
		end = line.find_first_of(" \t", pos);
		extension_cgi.push_back(line.substr(pos, end - pos));
	}
	return extension_cgi;
}
