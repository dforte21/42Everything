#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator &c){
	(void)c;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &c){
	(void)c;
	return (*this);
}

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
	map<string, ATarget *>::iterator start = targets.begin();
	map<string, ATarget *>::iterator end = targets.end();
	while (start != end)
	{
		delete start->second;
		++start;
	}
	targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget* t){
	if (t)
		targets.insert(pair<string, ATarget *>(t->getType(), t->clone()));
}

void	TargetGenerator::forgetTargetType(string const &t){
	map<string, ATarget *>::iterator it = targets.find(t);
	if (it != targets.end())
		delete it->second;
	targets.erase(t);
}

ATarget	*TargetGenerator::createTarget(string const &t){
	map<string, ATarget *>::iterator it = targets.find(t);
	if (it != targets.end())
		return (targets[t]);
	return NULL;
}
