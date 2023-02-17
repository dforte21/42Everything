#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ATarget.hpp"
#include <map>

using namespace std;


class Warlock {
	private:
		string name;
		string title;

		Warlock();
		Warlock(const Warlock &c);
		Warlock &operator=(const Warlock &c);

		map<string, ASpell *> spells;

	public:
		Warlock(string _name, string _title);
		~Warlock();

		const string &getTitle() const;
		const string &getName() const;
		void setTitle(const string &_title);
		void introduce() const;

		void	learnSpell( ASpell *s );
		void	forgetSpell( string _name );
		void	launchSpell( string _name, const ATarget &t );
};

#endif