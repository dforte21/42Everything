/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:42:29 by ddelladi          #+#    #+#             */
/*   Updated: 2023/02/08 17:07:58 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "Constructor called on MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		(*this)._inv[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	//std::cout << "Copy constructor called on MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = src._inv[i];
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & rhs)
{
	//std::cout << "Copy assignment operator called on MateriaSource" << std::endl;
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->_inv[i] = rhs._inv[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	//std::cout << "Destructor called on MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	i = 0;
	for (; i < 4; i++)
	{
		if (!this->_inv[i])
			break ;
	}
	if (i < 4)
		this->_inv[i] = m->clone();
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inv[i]->getType().compare(type))
			return (this->_inv[i]->clone());
	}
	return (0);
}
