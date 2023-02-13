#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <exception>

template<typename S>
class MutantStack : public std::stack<S>{
	public:
		MutantStack();
		MutantStack( const MutantStack &c );
		~MutantStack();
		MutantStack	&operator=( const MutantStack &c );
		typedef typename std::stack<S>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif