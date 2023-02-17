#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(const ATarget &c){
	*this = c;
}

ATarget::ATarget( string _type ) : type(_type){}

ATarget::~ATarget(){}

ATarget &ATarget::operator=(const ATarget &c){
	this->type = c.type;
	return (*this);
}

string	ATarget::getType() const{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell &a) const{
	cout << this->type << " has been " << a.getEffects() << "!\n";
}

//<TYPE> has been <EFFECTS>!