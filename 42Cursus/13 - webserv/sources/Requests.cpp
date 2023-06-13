#include "../includes/Server.hpp"

void Server::handleRequest(std::map<std::string, std::string> http_map, int fd) {
	if (this->checkRequest(http_map, fd)) {
		std::string method = http_map["HTTP_method"];
		if (method == "GET")
			this->handleGET(http_map, fd);
		// else if (method == "POST")
		else if (method == "DELETE")

			this->handleDELETE(http_map, fd);
	}

}

void	Server::handleDELETE(std::map<std::string, std::string> http_map, int fd) {
	;
}

bool Server::checkRequest(std::map<std::string, std::string> http_map, int fd) {
	sBMap alllowed_methods = _config.getAllowedMethods();
	if (alllowed_methods[http_map["HTTP_method"]] == false)
		return default_error_answer(405, fd);
	return true;
}

void	Server::handleGET(std::map<std::string, std::string> http_map, int fd) {
	std::cout << "sonoqui\n";
	std::ifstream body;
    if (!getBody(http_map["URL"], body, fd))
        return ;
	std::ostringstream oss;
	std::string b( (std::istreambuf_iterator<char>(body) ),
                       (std::istreambuf_iterator<char>()    ) );
	oss << "HTTP/1.1 200 OK\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << b.size() << "\r\n";
    // oss << "Connection: keep-alive\r\n";
    oss << "\r\n";
    oss << b;
	oss << "\r\n\n\r";
	std::string response(oss.str());
	if (send(fd, response.c_str(), response.size(), MSG_NOSIGNAL) == -1)
		std::cout << "Send error!\n";
// 	std::cout<< "send fd:" << fd << std::endl;
// 	std::cout << "root " << _config.getRoot() << " index: " << _config.getIndex().at(0) << std::endl;
// 	if (send(fd, "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!", 79, MSG_NOSIGNAL) == -1)
// 		std::cout << "Send error!\n";
}

bool Server::getBody(std::string url, std::ifstream &body, int fd) {
    if (url == "/") {
        sVec indexes = _config.getIndex();
	    std::vector<std::string>::iterator it = indexes.begin();
	    std::string	root = _config.getRoot() + "/";

	    while (1) {
	    	body.open(root + (*it));
	    	if (body.is_open() == true)
	    		return true;
	    	else
	    		body.close();
	    	it++;
	    	if (it == indexes.end()) {
	    		this->default_error_answer(404, fd);
	    		return false;
	    	}
	    }
    }
    else {
        body.open(url);
        if (body.is_open() == true)
            return true;
        body.close();
        this->default_error_answer(404, fd);
        return false;
    }
}