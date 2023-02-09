#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default"){
	//std::cout << "RobotomyRequestForm created\n";
}

RobotomyRequestForm::RobotomyRequestForm( std::string _target ) : AForm("RobotomyRequestForm", 72, 45), target(_target){
	//std::cout << "RobotomyRequestForm created\n";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &c ) : AForm(c), target(c.getTarget()){
	//std::cout << "RobotomyRequestForm created\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){
	//std::cout << "RobotomyRequestForm destroyed\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &c ){
	if (this == &c)
		return (*this);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!this->getSigned())
		throw(notSigned());
	else if (executor.getGrade() <= this->getExecGrade()){
		srand(time(nullptr));
		int risultato = rand() % 2;
		if (risultato == 0)
			std::cout << this->getTarget() << " has been robotomized successfully\n";
		else
			std::cout << "robotomization failed\n";
	}
	else
		throw(GradeTooHighException());
}

std::string	RobotomyRequestForm::getTarget() const{
	return (target);
}