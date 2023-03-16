#include "PmergeMe.hpp"

int main(int ac, char **av){
	if (ac < 2)
	{
		std::cerr << "Error, inserisci dei numeri\n";
		return (1);
	}
	try{
		PmergeMe a(av);
		a.vStartSort();
		a.sStartSort();
	}
	catch (std::exception &e){
		std::cerr << e.what();
		return (1);
	}
	return (0);
}