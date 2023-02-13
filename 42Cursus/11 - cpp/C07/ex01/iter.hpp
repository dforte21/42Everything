#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename I>
void	iter(I *addr, int len, void (*f)(I &n)){
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

#endif