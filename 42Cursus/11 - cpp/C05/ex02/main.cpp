#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	b("Carlo", 1);

try
	{
		ShrubberyCreationForm	s("prova");
		b.signForm(s);
		b.executeForm(s);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RobotomyRequestForm	r("prova2");
		b.signForm(r);
		b.executeForm(r);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat	z("Renato", 150);
	try
	{
		PresidentialPardonForm	p("offeso");
		b.signForm(p);
		b.executeForm(p);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PresidentialPardonForm	p2("molto offeso");
		b.signForm(p2);
		z.executeForm(p2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}