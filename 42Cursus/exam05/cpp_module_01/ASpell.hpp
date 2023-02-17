#pragma once

#include <iostream>
#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell{
	private:
		string name;
		string effects;
	public:
		ASpell();
		ASpell(const ASpell &c);
		ASpell( string _name, string _effect );
		virtual ~ASpell();

		ASpell &operator=(const ASpell &c);

		const string	&getName() const;
		const string	&getEffects() const;

		void	launch( const ATarget &t );

		virtual ASpell *clone() const = 0;
};