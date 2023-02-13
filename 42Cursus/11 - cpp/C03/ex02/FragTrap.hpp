#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &copy );
		virtual ~FragTrap( void );
		FragTrap	&operator=( const FragTrap &copy );
		void	highFivesGuys( void );
};

#endif