#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150){
	std::cout << "È nato un burocrate\n";
}

Bureaucrat::Bureaucrat( const std::string _name, int _grade) : name(_name), grade(_grade){
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	std::cout << "È nato un burocrate\n";
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ){
	*this = copy;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "È morto un burocrate\n";
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &copy ){
	if (this != &copy)
		return (*new(this) Bureaucrat(copy.getName(), copy.getGrade()));
	return (*this);
}

std::string	Bureaucrat::getName() const{
	return (this->name);
}

int	Bureaucrat::getGrade() const{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(){
	if (grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decrementGrade(){
	if (grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->grade++;
}

std::ostream&	operator<<(std::ostream & os, Bureaucrat const & b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}