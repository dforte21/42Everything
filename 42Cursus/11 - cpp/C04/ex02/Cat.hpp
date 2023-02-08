#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat( const Cat &copy );
		~Cat();
		Cat	&operator=( const Cat &copy );
		void	makeSound() const;
		void	printIdea( int index ) const;
};

#endif