#include "easyfind.hpp"

int main(){
	std::list<int>				arr;
	std::vector<int>			arr2;

	arr.push_back(10);
	arr.push_back(10);
	arr.push_back(10);
	arr.push_back(10);
	arr.push_back(5);
	arr.push_back(10);
	arr.push_back(10);
	arr.push_back(10);
	try
	{
		std::cout << *(::easyfind(arr, 5)) << std::endl;
		std::cout << *(::easyfind(arr, 10)) << std::endl;
		std::cout << *(::easyfind(arr, -1)) << std::endl;
	}
	catch (noResult& e)
	{
		std::cout << e.what() << std::endl;
	}
	arr2.push_back(10);
	arr2.push_back(10);
	arr2.push_back(10);
	arr2.push_back(10);
	arr2.push_back(5);
	arr2.push_back(10);
	arr2.push_back(10);
	arr2.push_back(10);
	try
	{
		std::cout << *(::easyfind(arr2, 5)) << std::endl;
		std::cout << *(::easyfind(arr2, 10)) << std::endl;
		std::cout << *(::easyfind(arr2, -1)) << std::endl;
	}
	catch (noResult& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}