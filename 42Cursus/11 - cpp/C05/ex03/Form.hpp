#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#define FALSE 0
#define TRUE 1

class Bureaucrat;

class AForm{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	public:
		AForm();
		AForm( std::string _name, int _signGrade, int _execGrade);
		AForm( const AForm &c );
		virtual ~AForm();
		AForm	&operator=( const AForm &c );

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void	beSigned( Bureaucrat &b );

		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual std::string getTarget() const = 0;

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
					return "Il Aform è già stato firmato\n";
				}
		};

};

std::ostream	&operator<<( std::ostream &os, const AForm &f);

#endif