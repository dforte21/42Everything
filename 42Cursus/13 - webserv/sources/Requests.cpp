#include "../includes/Server.hpp"

bool	Server::checkRequest(int fd, Config &location) {
	location = _locationMap["/"];
	location._location_name = "/";
	std::string temp_request = _requestMap["URL"];
	if (_locationMap.count(temp_request) == 0) {
		size_t pos = temp_request.size();
		while ((pos = temp_request.rfind('/', pos)) != std::string::npos){
			temp_request.resize(pos);
			if (_locationMap.count(temp_request) > 0) {
				location = _locationMap[temp_request];
				location._location_name = temp_request;
				break ;
			}
		}
	}
	else {
		location = _locationMap[temp_request];
		location._location_name = temp_request;
	}
	sBMap alllowed_methods = location.getAllowedMethods();
	if (alllowed_methods[_requestMap["HTTP_method"]] == false) {
		default_error_answer(405, fd, location);
		return false;
	}
	return true;
}

void	Server::parseRequest(std::string request) {
	std::size_t first = 0;
	std::size_t i = 0;

	const char *prova = request.c_str();
	std::string line;

	while (prova[i] != '\0') {
		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
			line = request.substr(first, i - first);
			std::size_t space = line.find(' ', 0);
			std::size_t space2 = line.find(' ', space + 1);
			_requestMap.insert(std::make_pair("HTTP_method", line.substr(0, space)));
			_requestMap.insert(std::make_pair("URL", line.substr(space + 1, space2 - space - 1)));
			_requestMap.insert(std::make_pair("protocol_version", line.substr(space2 + 1, line.length())));
			if (prova[i] != 4)
				i++;
			first = i + 1;
			break ;
		}
		i++;
	}
	size_t fine = request.rfind("\r\n\r\n");
	if (fine != std::string::npos) {
		std::cout<<"ultima "<< request.substr(fine+4)<<std::endl;
		_requestMap.insert(std::make_pair("Last", request.substr(fine+4)));
	}
	while (prova[i] != '\0') {
		if ((prova[i] == '\r' && prova[i + 1] == '\n') || prova[i] == 4){
			
			line = request.substr(first, i - first);
			if (prova[i] != 4)
				i++;
			first = i + 1;
		std::size_t mid = line.find(':', 0);
		if (mid != std::string::npos && line[mid] == ':' && line[mid + 1] == ' ')
			_requestMap.insert(std::make_pair(line.substr(0, mid), line.substr(mid + 2 , line.length())));
		else
			_requestMap.insert(std::make_pair(line.substr(0, line.length()), ""));
		}
		i++;
	}
}

void Server::handleRequest(int fd, Config &location) {
	std::string	methods[5] = {"GET", "POST", "DELETE", "HEAD", "PUT"};
	int	i;

	for (i = 0; i < 5; i++)
		if (methods[i] == _requestMap["HTTP_method"])
			break ;
	//std::cout << methods[i] << std::endl;
	switch(i)
	{
		case GET:
			this->handleGET(fd, location);
			break ;
		case PUT:
			this->handlePUT(fd, location);
			break ;
		case DELETE:
			this->handleDELETE(fd);
			break;
		default :	
			return this->default_error_answer(405, fd, location);
	}
}

void	Server::handleDELETE(int fd) {
	std::string url = _requestMap["URL"];
	Config		toDeleteLocation = _locationMap[url];

	(void)fd;
}

void	Server::handleGET(int fd, Config &location) {
	std::ifstream body;
	int status;
	std::ostringstream oss;

	oss << "HTTP/1.1 200 OK\r\n";
	std::cout<< "handleGET "<< _requestMap["URL"] << std::endl;
	std::cout<< "location name:" << location._location_name << std::endl;
	if (_requestMap["URL"] == "/favicon.ico") {
		if(!getIcon(body))
			return default_error_answer(404, fd, location);
		oss << "Content-Type: image/png\r\n";
	}
	else { 
		if ((status = getBody(body, location)) != 0)
			return default_error_answer(status, fd, location);
    	oss << "Content-Type: text/html\r\n";
	}
	std::cout<< "non va in errore\n";
	std::string b( (std::istreambuf_iterator<char>(body) ),
                       (std::istreambuf_iterator<char>()    ) );
    oss << "Content-Length: " << b.size() << "\r\n";
    // oss << "Connection: keep-alive\r\n";
    oss << "\r\n";
    oss << b;
	//oss << "\r\n\n\r"; //forse non va messo, sembra che il tester dia un errore
	std::string response(oss.str());

	if (send(fd, response.c_str(), response.size(), MSG_NOSIGNAL) == -1)
		std::cout << "Send error!\n";
// 	std::cout<< "send fd:" << fd << std::endl;
// 	std::cout << "root " << _config.getRoot() << " index: " << _config.getIndex().at(0) << std::endl;
// 	if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, MSG_NOSIGNAL) == -1)
// 		std::cout << "Send error!\n";
}

void	Server::handlePUT(int fd, Config &location) {
	//std::cout<<fd<<"handle PUT "<<location._location_name<<std::endl<<"LAST:"<<_requestMap["Last"]<<std::endl;
	if (_requestMap["Transfer-Encoding"] == "chunked")
		handleChunked(fd, location);

}

void Server::handleChunked(int fd, Config &location) {
	std::string line = _requestMap["Last"];
	if (line == "") {
		char buf[256];
		short nbytes = recv(fd, buf, 255, 0);
		buf[nbytes] = '\0';
		line += buf;
	}
		//std::cout<<"handlechunk "<< fd <<location._location_name<< " last "<<line<<std::endl;
		//std::cout<<"passo1"<<std::endl;
		std::stringstream content;
		std::size_t chunkSize = getHexSize_E_Content(line, content);
	while (content.str().size() < chunkSize && chunkSize != 1000) {
		char buf[256];
		//std::cout<<"passo2"<<std::endl;
		
		short nbytes = recv(fd, buf, 255, 0);
		buf[nbytes] = '\0';
		if (content.str().size() + nbytes > chunkSize) {
			std::string temp(buf);
			chunkSize += getHexSize_E_Content(temp, content);
		}
		else
			content << buf;
		//std::cout<<"buff: "<< buf<< "content size: "<<content.str().size() << "nbytes "<< nbytes<<"chuck size "<<chunkSize<< std::endl;
		if (content.str().size() >= chunkSize)
			break ;
	}
		//std::cout << "size "<<chunkSize<<std::endl<< "content:"<<content.str()<<std::endl<<" content size "<<content.str().size()<<std::endl;
	std::string filepath(location.getRoot());
	//std::cout<<"filepath dopo getroot "<< filepath<<std::endl;
	//std::cout<<"passo3"<<std::endl;
	line = _requestMap["URL"];
	filepath += line.substr(line.find(location._location_name) + location._location_name.size());
	if (checkTryFiles("$uri", location)) {
		std::ofstream file(filepath.c_str(), std::ios::out | std::ios::trunc);
		//std::cout<< "tentativo prima: " << filepath << std::endl;
		if (file.is_open()) {
			file << content.str();
			file.close();
			return default_error_answer(201, fd, location);
		}
		file.close();
	}
	if (checkTryFiles("$uri/", location)){
		if (filepath.at(filepath.size() - 1) != '/')
			filepath.push_back('/');
		sVec indexes = location.getIndex();
		for (sVec::iterator it = indexes.begin(); it != indexes.end(); it++)
		{
			std::ofstream file(filepath.c_str(), std::ios::out | std::ios::trunc) ;
			//std::cout<< "tentativo: " << filepath + *it << " it:"<<*it<< std::endl;
			file.open((filepath + *it).c_str());
			if (file.is_open() == true){
				file << content.str();
				file.close();
				return default_error_answer(201, fd, location);
			}
			file.close();
		}
	}
	std::cout<<"error"<<std::endl;
	default_error_answer(404, fd, location);

}

size_t	Server::getHexSize_E_Content(std::string &line, std::stringstream &content) {
	std::size_t pos = line.find("\r\n");
	std::stringstream c(line.substr(0, pos));
	std::size_t chunkSize = 0;
	c >> std::hex >> chunkSize;
	content << line.substr(pos + 2);
	return (chunkSize);
}

int Server::getBody(std::ifstream &body, Config &location) {
	std::string resource_path = _requestMap["URL"];
	std::string root = location.getRoot();

	/*if (root.at(root.size() - 1) != '/')
		root += "/";*/
	if (location._location_name == "/") {
		resource_path = root;
	}
	else {
		std::cout<<"resource_path prima:"<<resource_path<<std::endl;
		size_t pos = resource_path.find(location._location_name);

		resource_path.replace(pos, location._location_name.size(), root);
		pos = resource_path.find("//");
		std::cout << "find pos:"<< pos<<" resource.size:"<< resource_path.size()<<std::endl;
		if (pos != std::string::npos)
			resource_path.erase(pos, 1);
		std::cout<<"resource_path at size -1:"<<resource_path.at(resource_path.size() - 1) <<std::endl;
	}
	std::cout<<"check try files $uri "<< this->checkTryFiles("$uri", location)<<std::endl;
	if (!isDirectory(resource_path) && this->checkTryFiles("$uri", location)) {
		body.open(resource_path.c_str());
		if (body.is_open() == true){std::cout<<"no dir open file"<<std::endl;
				return 0;}
		else
			body.close();
	}
	if (this->checkTryFiles("$uri/", location)) {
		if (resource_path.at(resource_path.size() - 1) != '/')
			resource_path.push_back('/');
		std::cout<<"resource path:"<<resource_path<<std::endl;
		sVec	indexes = location.getIndex();
		for (sVec::iterator it = indexes.begin(); it != indexes.end(); it++)
		{
			std::cout<< "tentativo: " << resource_path + *it << std::endl;
			body.open((resource_path + *it).c_str());
			if (body.is_open() == true)
				return 0;
			body.close();
		}
	}
	std::cout<<"final return"<< std::endl;
	return 404;
}

bool Server::getIcon(std::ifstream &body) {
	body.open("fake_site/choco.png");
	if (body.is_open())
		return true;
	body.close();
	return false;
}

bool isDirectory(const std::string& path) {
	struct stat fileStat;
	if (stat(path.c_str(), &fileStat) == 0)
		return S_ISDIR(fileStat.st_mode);
	return false;
}

bool	Server::checkTryFiles(std::string check, Config &location) {
	sVec try_files = location.getTryFiles();
	std::cout<<"check:"<<check<<"size"<<try_files.size()<<std::endl;
	for (std::vector<std::string>::iterator it = try_files.begin(); it != try_files.end(); it++) {
		std::cout<<"it:"<<(*it)<<std::endl;
		if ((*it) == check)
			return true;
	}
	std::cout<<"esco:"<<check<<std::endl;
	return false;
}