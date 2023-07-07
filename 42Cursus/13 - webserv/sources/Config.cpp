#include "../includes/Config.hpp"

Config::Config()
	: _listen(8080), _client_max_body_size(0),
		_autoindex(false) {

	_allowed_methods.insert(std::pair<std::string, bool>("GET", false));
	_allowed_methods.insert(std::pair<std::string, bool>("POST", false));
	_allowed_methods.insert(std::pair<std::string, bool>("HEAD", false));
	_allowed_methods.insert(std::pair<std::string, bool>("PUT", false));
	_allowed_methods.insert(std::pair<std::string, bool>("DELETE", false));
}

Config::Config(std::string &serverBody)
	: _listen(8080), _client_max_body_size(0),
		_autoindex(false) {
	std::string	line;
	std::string	directive;
	size_t		pos;
	std::string	locationName;

	_allowed_methods.insert(std::pair<std::string, bool>("GET", true));
	_allowed_methods.insert(std::pair<std::string, bool>("POST", false));
	_allowed_methods.insert(std::pair<std::string, bool>("HEAD", true));
	_allowed_methods.insert(std::pair<std::string, bool>("PUT", false));
	_allowed_methods.insert(std::pair<std::string, bool>("DELETE", false));

	while ((pos = serverBody.find_first_of('\n')) != std::string::npos)
	{
		line = serverBody.substr(serverBody.find_first_not_of(" \t\n"), pos);
		if (this->doDirective(line))
			this->addLocation(serverBody);
		else
			serverBody.erase(0, pos + 1);
	}
}

Config::~Config(void) {
	
}

Config	&Config::operator=(Config &rhs) {
	if (this == &rhs)
		return *this;
	
	this->_listen = rhs.getListen();
	this->_server_name = rhs.getServerName();
	if (this->_root.empty())
		this->_root = rhs.getRoot();
	if (this->_index.empty())
		this->_index = rhs.getIndex();
	if (this->_error_page.empty())
		this->_error_page = rhs.getErrorPage();
	if (this->_client_max_body_size == 0)
		this->_client_max_body_size = rhs.getClientMaxBodySize();
	if (this->_allowed_methods["GET"] == false && this->_allowed_methods["POST"] == false &&
			this->_allowed_methods["HEAD"] == false && this->_allowed_methods["PUT"] == false &&
				this->_allowed_methods["DELETE"] == false)
		this->_allowed_methods = rhs.getAllowedMethods();
	if (this->_autoindex == false)
		this->_autoindex = rhs.getAutoindex();
	if (this->_try_files.empty())
		this->_try_files = rhs.getTryFiles();
	if (this->_cgi_pass.empty())
		this->_cgi_pass = rhs.getCgiPass();
	if (this->_extension_cgi.empty())
		this->_extension_cgi = rhs.getExtensionCgi();
	this->_return = rhs.getReturn();
	this->_locationMap = rhs.getLocationMap();

	return *this;
}

int	Config::doDirective(std::string &line) {
	std::string		directive;
	int				i;
	std::string		directiveAr[] = {"listen", "server_name", "root", "index", "error_page", 
		"client_max_body_size", "allowed_methods", "location", "autoindex", "try_files",
			"cgi_pass", "extension_cgi", "return"};

	directive = line.substr(0, line.find_first_of(" \t\n"));
	i = 0;
	while (i < 13)
	{
		if (directive == directiveAr[i])
			break ;
		i++;
	}
	switch(i)
	{
		case 0 :
			_listen = this->setListen(line);
			break ;
		case 1 :
			_server_name = this->setServerName(line);
			break ;
		case 2 :
			_root = this->setRoot(line);
			break ;
		case 3 :
			_index = this->setIndex(line);
			break ;
		case 4 :
			_error_page = this->setErrorPage(line);
			break ;
		case 5 :
			_client_max_body_size = this->setClientMaxBodySize(line);
			break ;
		case 6 :
			_allowed_methods = this->setAllowedMethods(line);
			break ;
		case 7 :
			return 1;
		case 8 :
			_autoindex = this->setAutoindex(line);
			break ;
		case 9 :
			_try_files = this->setTryFiles(line);
			break ;
		case 10 :
			_cgi_pass = this->setCgiPass(line);
			break ;
		case 11 :
			_extension_cgi = this->setExtensionCgi(line);
			break ;
		case 12 :
			_return = this->setReturn(line);
			break ;
		default :
			if (directive.find_first_not_of("{}\n") != std::string::npos)
				throw badConfigFile();
	}
	return 0;
}

void	Config::addLocation(std::string &serverBody) {
	size_t		pos;
	size_t		end;
	std::string	locationName;
	std::string	locationBody;

	pos = serverBody.find("location");
	serverBody.erase(0, pos + 8);
	pos = serverBody.find_first_not_of(" \t\n");
	end = serverBody.find("{");
	if (pos == end || pos == std::string::npos || end == std::string::npos)
		throw badConfigFile();
	end -= 1;
	while (std::isspace(serverBody.at(end)))
		end--;
	locationName = serverBody.substr(pos, end);
	pos = end + 1;
	end = serverBody.find_first_of("}");
	locationBody = serverBody.substr(pos, end);
	Config locationConfig(locationBody);
	locationConfig = *this;
	_locationMap.insert(std::pair<std::string, Config>(locationName, locationConfig));
	serverBody.erase(0, end);
}

void	Config::displayConfig(void) const {
	sVec	vec;
	std::map<std::string, bool> map;
	iSPair	pair;

	std::cout << "listen: " << this->getListen() << std::endl;
	std::cout << "server_name: ";
	vec = this->getServerName();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "root: " << this->getRoot() << std::endl;
	std::cout << "index: ";
	vec = this->getIndex();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "error_page: ";
	vec = this->getErrorPage();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "client_max_body_size: " << this->getClientMaxBodySize() << std::endl;
	std::cout << "allowed_methods: ";
	map = getAllowedMethods();
	std::cout << std::boolalpha;
	for(std::map<std::string, bool>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << '=' << it->second << ", ";
	std::cout << std::endl;
	std::cout << "autoindex: " << this->getAutoindex() << std::endl;
	std::cout << "try_files: ";
	vec = this->getTryFiles();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "cgi_pass: " << this->getCgiPass() << std::endl;
	std::cout << "extension_cgi: ";
	vec = this->getExtensionCgi();
	for(sVec::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	pair = this->getReturn();
	std::cout << "return: " << pair.first << ' ' << pair.second << std::endl;
	std::cout << std::endl;
}

const char *Config::badConfigFile::what() const throw() {
	return "Bad config file";
}
