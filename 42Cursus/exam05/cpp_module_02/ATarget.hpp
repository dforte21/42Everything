#pragma once

#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget{
	private:
		string type;
	public:
		ATarget();
		ATarget(const ATarget &c);
		ATarget( string _type );
		virtual ~ATarget();

		ATarget &operator=(const ATarget &c);

		string	getType() const;

		void	getHitBySpell(const ASpell &a) const;

		virtual ATarget *clone() const = 0;
};
