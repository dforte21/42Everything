#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

using namespace std;

class Warlock {
	private:
		string name;
		string title;

		Warlock();
		Warlock(const Warlock &c);
		Warlock &operator=(const Warlock &c);
	public:
		Warlock(string _name, string _title);
		~Warlock();

		const string &getTitle() const;
		const string &getName() const;
		void setTitle(const string &_title);
		void introduce() const;
};

#endif