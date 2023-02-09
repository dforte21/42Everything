#include "Form.hpp"

int	main()
{
	Bureaucrat	b("Carlo", 10);

	try
	{
		Form	f("Primo form", 120, 5);
		std::cout << "Test firma form con grado ok e uno con grado sbagliato\n" << f;
		std::cout << b;
		b.signForm(f);
		std::cout << f;
		Form	g(f);
		Form	h("Secondo form", 1, 3);
		b.signForm(h);
		std::cout << h;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	f("Primo form", 120, 5);
		std::cout << "\nTest firma form già firmato\n" << f;
		std::cout << b;
		b.signForm(f);
		std::cout << f;
		b.signForm(f);
		std::cout << f;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}