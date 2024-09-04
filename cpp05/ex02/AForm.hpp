#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		~AForm(void);
		AForm(const AForm &other);
		AForm(std::string name, int sign_grade, int exec_grade);

		bool				getStatus(void) const;
		std::string 		getName(void) const;
		unsigned int 		getSignGrade(void) const;
		unsigned int 		getExecGrade(void) const;
		void				setStatus(bool status);

		void				beSigned(const Bureaucrat &bcat);

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int 	_sign_grade;
		const unsigned int 	_exec_grade;

		AForm				&operator=(const AForm &other);

};

std::ostream& 				operator<<(std::ostream& streamRef,const AForm& form);

#endif