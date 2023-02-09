#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default"){
	//std::cout << "PresidentialPardonForm created\n";
}

PresidentialPardonForm::PresidentialPardonForm( std::string _target ) : AForm("PresidentialPardonForm", 25, 5), target(_target){
	//std::cout << "PresidentialPardonForm created\n";
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &c ) : AForm(c), target(c.getTarget()){
	//std::cout << "PresidentialPardonForm created\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
	//std::cout << "PresidentialPardonForm destroyed\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &c ){
	if (this == &c)
		return (*this);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!this->getSigned())
		throw(notSigned());
	else if (executor.getGrade() <= this->getExecGrade())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
	else
		throw(GradeTooHighException());
}

std::string	PresidentialPardonForm::getTarget() const{
	return (target);
}