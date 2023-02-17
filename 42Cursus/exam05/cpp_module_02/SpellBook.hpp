#pragma once

#include "ASpell.hpp"
#include <map>

using namespace std;

class SpellBook{
	private:
		map<string, ASpell *> spells;

		SpellBook(const SpellBook &c);
		SpellBook &operator=(const SpellBook &c);
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *s);
		void	forgetSpell(string const &s);
		ASpell	*createSpell(string const &s);
};