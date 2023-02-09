#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat( const std::string _name, int _grade);
		Bureaucrat( const Bureaucrat &copy );
		~Bureaucrat();
		Bureaucrat	&operator=( const Bureaucrat &copy );

		std::string	getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm( Form &f );

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw()
				{
					return "Il grado è troppo alto";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw()
				{
					return "Il grado è troppo basso";
				}
		};
};

std::ostream&	operator<<(std::ostream & os, Bureaucrat const & b);

#endif