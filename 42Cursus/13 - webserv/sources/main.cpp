#include "../includes/Cluster.hpp"

int main(int argc, char *argv[]){
	if (argc != 2)
		return 1;
	try {
		Cluster	cluster(argv[1]);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}