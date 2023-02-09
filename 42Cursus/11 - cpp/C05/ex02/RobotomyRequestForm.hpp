#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string _target );
		RobotomyRequestForm( const RobotomyRequestForm &c );
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &c );

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