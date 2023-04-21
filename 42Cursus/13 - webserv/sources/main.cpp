#include "../includes/Server.hpp"

int main(int argc, char *argv[]){
	Server *obj = new Server();
	(void)argc;
	(void)argv;
	delete (&obj);
}