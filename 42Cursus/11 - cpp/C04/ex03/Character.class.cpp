/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:44:45 by ddelladi          #+#    #+#             */
/*   Updated: 2023/02/08 17:07:27 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character() : _name("no_name")
{
	//std::cout << "Default constructor called on Character" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	//std::cout << "Constructor called on Character" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(Character const & src) : _name(src._name)
{
	//std::cout << "Copy constructor called on Character" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = src._inv[i];
}

Character&	Character::operator=(Character const & rhs)
{
	//std::cout << "Copy assignment operator called on Character" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = rhs._inv[i];
	return (*this);
}

Character::~Character()
{
	//std::cout << "Destructor called on Character" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inv[i])
		{
			this->_inv[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	this->_inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	this->_inv[idx]->use(target);
}
