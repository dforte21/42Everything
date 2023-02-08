#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal( void );
		Animal( const Animal &copy );
		virtual ~Animal( void );
		Animal	&operator=( const Animal &copy );
		virtual void	makeSound() const;
		std::string	getType() const;
		void	setType( const std::string _type );
};

#endif