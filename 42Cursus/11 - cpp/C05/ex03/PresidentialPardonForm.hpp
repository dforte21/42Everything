#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string _target );
		PresidentialPardonForm( const PresidentialPardonForm &c );
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &c );

		void		execute(Bureaucrat const & executor) const;
		std::string	getTarget() const;
		
		class notSigned	: std::exception{
			public:
				virtual const char *what() const throw(){
					return "il form non è firmato\n";
				}
		};
};

#endif