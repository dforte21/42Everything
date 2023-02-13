#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string	name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string _name);
		DiamondTrap( const DiamondTrap &copy );
		~DiamondTrap( void );
		DiamondTrap	&operator=(const DiamondTrap &copy );
		void	whoAmI();
		void	attack( const std::string &target);
};

#endif