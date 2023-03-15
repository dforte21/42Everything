#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cerr << "Error, wrong number of args, [./RPM expr]\n";
		return (1);
	}
	try{
		std::string exp = av[1];
		RPN a(exp);
		a.printSolution();
	}
	catch (std::exception &e){
		std::cerr << e.what();
		return (1);
	}
	return (0);
}