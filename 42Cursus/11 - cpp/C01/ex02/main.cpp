#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "STRING    address: " << &string << std::endl;
	std::cout << "stringPTR address: " << &stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl << std::endl;

	std::cout << "STRING    value: " << string << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}