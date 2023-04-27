#include "../includes/webserv.hpp"
#include "../includes/Server.hpp"
#include "../includes/Config.hpp"

int main(int argc, char *argv[]){
	//Server *obj = new Server();
	//Config parser(argv[1]);
	try {
		Server obj;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	(void)argc;
	(void)argv;
	//delete (&obj);
}