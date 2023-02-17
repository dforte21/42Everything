#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(const ASpell &c){
	*this = c;
}

ASpell::ASpell( string _name, string _effect ) : name(_name), effects(_effect){}

ASpell::~ASpell(){}

ASpell &ASpell::operator=(const ASpell &c){
	this->name = c.name;
	this->effects = c.effects;
	return (*this);
}

const string	&ASpell::getName() const{
	return (name);
}

const string	&ASpell::getEffects() const{
	return (effects);
}

void	ASpell::launch( const ATarget &t ){
	t.getHitBySpell(*this);
}