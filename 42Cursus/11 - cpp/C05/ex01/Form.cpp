#include "Form.hpp"

Form::Form() : name("Default"), isSigned(FALSE), signGrade(150), execGrade(150){
	//std::cout << "Form has been created\n";
}

Form::Form( std::string _name, int _signGrade, int _execGrade) : name(_name), isSigned(FALSE), signGrade(_signGrade), execGrade(_execGrade){
	if (this->signGrade < 1 || this->execGrade < 1)
		throw (GradeTooHighException());
	else if(this->signGrade > 150 || this->execGrade > 150)
		throw (GradeTooLowException());
	//std::cout << "Form has been created\n";
}

Form::Form( const Form &c ) : name(c.getName()), isSigned(FALSE), signGrade(c.getSignGrade()), execGrade(c.getExecGrade()){
	if (this->signGrade < 1 || this->execGrade < 1)
		throw (GradeTooHighException());
	else if(this->signGrade > 150 || this->execGrade > 150)
		throw (GradeTooLowException());
	//std::cout << "Form has been created\n";
}

Form::~Form(){
	//std::cout << "Form has been destroyed\n";
}

Form	&Form::operator=( const Form &c ){
	if (this != &c)
		return (*new(this) Form(c.getName(), c.getSignGrade(), c.getExecGrade()));
	return (*this);
}

std::string	Form::getName() const{
	return (this->name);
}

bool	Form::getSigned() const{
	return (this->isSigned);
}

int	Form::getSignGrade() const{
	return (this->signGrade);
}

int	Form::getExecGrade() const{
	return (this->execGrade);
}

void	Form::beSigned( Bureaucrat &b ){
	if (this->isSigned == TRUE)
		throw(alreadySigned());
	else if (b.getGrade() <= this->signGrade)
		this->isSigned = TRUE;
	else
		throw(GradeTooHighException());
}

std::ostream	&operator<<( std::ostream &os, const Form &f){
	os << "Form numero: " << f.getName() << "\n stato: ";
	if (!f.getSigned())
		os << "NON FIRMATO\n";
	else
		os << "FIRMATO\n";
	os << "Grado minimo per firmare: " << f.getSignGrade() << " | Grado minimo per eseguire: " << f.getExecGrade() << std::endl;
	return (os); 
}