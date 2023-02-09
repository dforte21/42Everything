#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
	private:
		std::string target;
		static std::string const	_trees[3];
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string _target );
		ShrubberyCreationForm( const ShrubberyCreationForm &c );
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &c );

		void		execute(Bureaucrat const & executor) const;
		void		writeFile() const;
		std::string	getTarget() const;

		class openError : std::exception{
			public:
				virtual const char *what() const throw(){
					return "Il file non può essere creato\n";
				}
		};

		class notSigned	: std::exception{
			public:
				virtual const char *what() const throw(){
					return "il form non è firmato\n";
				}
		};
};

#endif