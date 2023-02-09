#include "Intern.hpp"

std::string const Intern::_forms[3] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

Intern::Intern() : _idx(0), _nForms(3)
{
	std::cout << "Default constructor called on Intern" << std::endl;
}

Intern::Intern(Intern const & src) : _idx(0), _nForms(3)
{
	std::cout << "Copy constructor called on Intern" << std::endl;
	(void)src;
}

Intern&	Intern::operator=(Intern const & rhs)
{
	std::cout << "Copy assignment operator called on Intern" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_idx = 0;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor called on Intern" << std::endl;
}

void	Intern::searchForm(std::string f)
{
	for (int i = 0; i < this->_nForms; i++)
	{
		if (!f.compare(this->_forms[i]))
		{
			this->_idx = i;
			return ;
		}
	}
	throw (Intern::NoExistingForm());
}

AForm*	Intern::makeForm(std::string f, std::string target)
{
	std::cout << "Intern creates " << target << std::endl;
	try
	{
		searchForm(f);
		switch (this->_idx)
		{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (NULL);
}