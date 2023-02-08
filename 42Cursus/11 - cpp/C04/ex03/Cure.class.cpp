/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:37:47 by ddelladi          #+#    #+#             */
/*   Updated: 2023/02/08 17:07:35 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.class.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Default constructor called on Cure" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(convertToTypeStr(type))
{
	//std::cout << "Constructor called on Cure" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src.getType())
{
	//std::cout << "Copy constructor called on Cure" << std::endl;
}

Cure&	Cure::operator=(Cure const & rhs)
{
	//std::cout << "Copy assignment operator called on Cure" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

Cure::~Cure()
{
	//std::cout << "Destructor called on Cure" << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(this->getType()));
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
