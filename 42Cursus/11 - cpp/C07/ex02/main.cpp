#include "Array.hpp"

int main(){
	Array<int>	a(10);

	for (int i = 0; i <= 10; i++)
	{
		try{
			a.setValue(2, i);
			std::cout << i + 1 << ":\t" << a.getValue(i) << std::endl;
		}
		catch( std::exception &e ){
			std::cerr << i + 1 << ":\t" << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "size is:\t" << a.getSize() << std::endl;
}