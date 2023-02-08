/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:37:54 by ddelladi          #+#    #+#             */
/*   Updated: 2023/02/08 17:07:45 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Default constructor called on Ice" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(convertToTypeStr(type))
{
	//std::cout << "Constructor called on Ice" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src.getType())
{
	//std::cout << "Copy constructor called on Ice" << std::endl;
}

Ice&	Ice::operator=(Ice const & rhs)
{
	//std::cout << "Copy assignment operator called on Ice" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Destructor called on Ice" << std::endl;
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice(this->getType()));
}

std::string	convertToTypeStr(std::string s)
{
	std::string	ret;

	ret = s;
	ret[0] = tolower(ret[0]);
	return (ret);
}
