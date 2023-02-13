#include "MutantStack.hpp"

#include "MutantStack.hpp"

template <typename S>
MutantStack<S>::MutantStack()
{}

template <typename S>
MutantStack<S>::MutantStack(MutantStack const & c)
{
	*this = c;
}

template <typename S>
MutantStack<S>&	MutantStack<S>::operator=(MutantStack const & c)
{
	(void)c;
	return (*this);
}

template <typename S>
MutantStack<S>::~MutantStack()
{}

template <typename S>
typename MutantStack<S>::iterator	MutantStack<S>::begin()
{
	return (this->c.begin());
}

template <typename S>
typename MutantStack<S>::iterator	MutantStack<S>::end()
{
	return (this->c.end());
}