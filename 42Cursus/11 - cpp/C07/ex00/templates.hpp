#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template <typename V>
void	swap(V &a, V &b){
	V c = a;
	a = b;
	b = c;
}

template <typename M>
M	min(M a, M b){
	if (a < b)
		return (a);
	return (b);
}

template <typename N>
N	max(N a, N b){
	if (a > b)
		return (a);
	return (b);
}

#endif