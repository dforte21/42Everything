#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <exception>

class noResult : public std::exception{
	public:
		virtual const char *what() const throw(){
			return ("No occurency found");
		}
};

template <typename T>
typename T::iterator	easyfind(T a, int tofind){
	typename T::iterator it;
	it = std::find(a.begin(), a.end(), tofind);
	if (it == a.end())
		throw(noResult());
	return (it);
}

#endif