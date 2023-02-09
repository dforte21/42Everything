#include "ShrubberyCreationForm.hpp"

std::string const	ShrubberyCreationForm::_trees[3] = 
{
	"                  **                  	\n" \
	"                 ****                 	\n" \
	"                ******                	\n" \
	"               ********               	\n" \
	"              **********              	\n" \
	"                  |||                 	\n" \
	"                  |||                 	\n" \
	"                                      	\n",
	"              ##########              	\n" \
	"              #        #              	\n" \
	"              #        #              	\n" \
	"              ##########              	\n" \
	"                  !!!                 	\n" \
	"                  !!!                 	\n" \
	"                                      	\n",
	"            °  _/     °  _/          \n" \
	"          ° \\/ \\    \\  /        °    \n" \
	"          \\__|    °    \\/    __/     \n" \
	"             |    \\     \\   /  \\    \n" \
	"              \\____|_   |___/   °   \n" \
	"                     |  |              \n" \
	"                      ||               \n" \
	"                      ||               \n" \
	"                                      	\n"
};

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default"){
	//std::cout << "ShrubberyCreationForm created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string _target ) : AForm("ShrubberyCreationForm", 145, 137), target(_target){
	//std::cout << "ShrubberyCreationForm created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &c ) : AForm(c), target(c.getTarget()){
	//std::cout << "ShrubberyCreationForm created\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	//std::cout << "ShrubberyCreationForm destroyed\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &c ){
	if (this == &c)
		return (*this);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!this->getSigned())
		throw(notSigned());
	else if (executor.getGrade() <= this->getExecGrade()){
		try{
			writeFile();
		}
		catch (std::exception &e){
			throw(openError());
		}
	}
	else
		throw(GradeTooHighException());
}

void		ShrubberyCreationForm::writeFile() const{
	std::ofstream f(this->target + "_shrubbery", std::ios::out);
	if (f.is_open()){
		for (int i  = 0; i < 3; i++)
			f << this->_trees[i];
		f.close();
	}
	else
		throw(openError());
}

std::string	ShrubberyCreationForm::getTarget() const{
	return (target);
}