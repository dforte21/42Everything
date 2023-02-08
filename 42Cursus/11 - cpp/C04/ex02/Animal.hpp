#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal{
	protected:
		std::string type;
	public:
		AAnimal( void );
		AAnimal( const AAnimal &copy );
		virtual ~AAnimal( void );
		AAnimal	&operator=( const AAnimal &copy );
		virtual void	makeSound() const;
		virtual void	printIdea( int index ) = 0;
		std::string	getType() const;
		void	setType( const std::string _type );
};

#endif