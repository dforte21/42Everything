#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &c){
	(void)c;
}

SpellBook &SpellBook::operator=(const SpellBook &c){
	(void)c;
	return (*this);
}

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
	map<string, ASpell *>::iterator start = spells.begin();
	map<string, ASpell *>::iterator end = spells.end();

	while (start != end)
	{
		if (start->second)
			delete start->second;
		++start;
	}
	spells.clear();
}

void	SpellBook::learnSpell(ASpell *s){
	if (s)
		spells.insert(pair<string, ASpell *>(s->getName(), s->clone()));
}

void	SpellBook::forgetSpell(string const &s){
	map<string, ASpell *>::iterator it = this->spells.find(s);
	if (it != spells.end())
		delete it->second;
	spells.erase(s);
}

ASpell	*SpellBook::createSpell(string const &s){
	map<string, ASpell *>::iterator it = spells.find(s);
	if (it != spells.end())
		return spells[s];
	return NULL;
}
