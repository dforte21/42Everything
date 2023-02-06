#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

typedef unsigned int uint;

class ClapTrap{
	private:
		std::string	name;
		uint	hP;
		uint	eP;
		uint	aD;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &copy );
		virtual ~ClapTrap( void );
		ClapTrap	&operator=(const ClapTrap &copy);
		void	attack(const std::string& target);
		void	takeDamage(uint amount);
		void	beRepaired(uint amount);
		std::string	getName( void ) const;
		uint	getAd( void ) const;
		uint	getHp( void ) const;
		uint	getEp( void ) const;
		void	setHp( uint hp );
		void	setEp( uint ep );
		void	setAd( uint ad );
		void	setName( std::string name );
};

#endif