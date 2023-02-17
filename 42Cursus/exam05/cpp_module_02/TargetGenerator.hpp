#pragma once

#include "ATarget.hpp"
#include <map>

using namespace std;

class TargetGenerator{
	private:
		map<string, ATarget *> targets;

		TargetGenerator(const TargetGenerator &c);
		TargetGenerator &operator=(const TargetGenerator &c);
	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget* t);
		void	forgetTargetType(string const &t);
		ATarget	*createTarget(string const &t);

};