#include "Form.hpp"

AForm::AForm() : name("Default"), isSigned(FALSE), signGrade(150), execGrade(150){
	//std::cout << "AForm has been created\n";
}

AForm::AForm( std::string _name, int _signGrade, int _execGrade) : name(_name), isSigned(FALSE), signGrade(_signGrade), execGrade(_execGrade){
	if (this->signGrade < 1 || this->execGrade < 1)
		throw (GradeTooHighException());
	else if(this->signGrade > 150 || this->execGrade > 150)
		throw (GradeTooLowException());
	//std::cout << "AForm has been created\n";
}

AForm::AForm( const AForm &c ) : name(c.getName()), isSigned(FALSE), signGrade(c.getSignGrade()), execGrade(c.getExecGrade()){
	if (this->signGrade < 1 || this->execGrade < 1)
		throw (GradeTooHighException());
	else if(this->signGrade > 150 || this->execGrade > 150)
		throw (GradeTooLowException());
	//std::cout << "AForm has been created\n";
}

AForm::~AForm(){
	//std::cout << "AForm has been destroyed\n";
}

AForm	&AForm::operator=( const AForm &c ){
	if (this == &c)
		return (*this);
	this->isSigned = false;
	if (this->signGrade > 150 || this->execGrade > 150)
		throw (AForm::GradeTooLowException());
	if (this->signGrade < 1 || this->execGrade < 1)
		throw (AForm::GradeTooHighException());
	return (*this);
}

std::string	AForm::getName() const{
	return (this->name);
}

bool	AForm::getSigned() const{
	return (this->isSigned);
}

int	AForm::getSignGrade() const{
	return (this->signGrade);
}

int	AForm::getExecGrade() const{
	return (this->execGrade);
}

void	AForm::beSigned( Bureaucrat &b ){
	if (this->isSigned == TRUE)
		throw(alreadySigned());
	else if (b.getGrade() <= this->signGrade)
		this->isSigned = TRUE;
	else
		throw(GradeTooHighException());
}

std::ostream	&operator<<( std::ostream &os, const AForm &f){
	os << "AForm numero: " << f.getName() << "\n stato: ";
	if (!f.getSigned())
		os << "NON FIRMATO\n";
	else
		os << "FIRMATO\n";
	os << "Grado minimo per firmare: " << f.getSignGrade() << " | Grado minimo per eseguire: " << f.getExecGrade() << std::endl;
	return (os); 
}