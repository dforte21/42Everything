#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#define FALSE 0
#define TRUE 1

class Bureaucrat;

class Form{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	public:
		Form();
		Form( std::string _name, int _signGrade, int _execGrade);
		Form( const Form &c );
		~Form();
		Form	&operator=( const Form &c );

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void	beSigned( Bureaucrat &b );

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw()
				{
					return "Il grado richiesto per firmare è più alto\n";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw()
				{
					return "Il grado richiesto per firmare è più basso\n";
				}
		};
		class alreadySigned : public std::exception{
			public:
				virtual const char *what() const throw()
				{
					return "Il form è già stato firmato\n";
				}
		};

};

std::ostream	&operator<<( std::ostream &os, const Form &f);

#endif