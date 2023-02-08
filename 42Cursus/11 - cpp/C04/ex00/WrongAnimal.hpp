#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal : public Animal{
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &copy );
		~WrongAnimal();
		WrongAnimal	&operator=( const WrongAnimal &copy );
};

#endif