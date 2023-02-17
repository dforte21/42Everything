#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(const Warlock &c){
	c.getName();
}

Warlock &Warlock::operator=(const Warlock &c){
	c.getName();
	return (*this);
}

Warlock::Warlock(string _name, string _title) : name(_name), title(_title){
	spells = new SpellBook();
	cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
	delete (spells);
	cout << this->name << ": My job here is done!\n";
}

const string &Warlock::getTitle() const{
	return (this->title);
}

const string &Warlock::getName() const{
	return (this->name);
}

void Warlock::setTitle(const string &_title){
	this->title = _title;
}

void Warlock::introduce() const{
	cout << this->name << ": I am " << this->name << ", "<< this->title << "!\n";
}

void	Warlock::learnSpell( ASpell *s ){
	spells->learnSpell(s);
}

void	Warlock::forgetSpell( string _name ){
	spells->forgetSpell(_name);
}

void	Warlock::launchSpell( string _name, const ATarget &t ){
	ASpell *spell = spells->createSpell(_name);
	if (spell)
		spell->launch(t);
}
