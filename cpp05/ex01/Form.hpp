#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

class Bureaucrat;

class Form
{
	public:
		Form(void);
		~Form(void);
		Form(const Form &other);
		Form(std::string name, int sign_grade, int exec_grade);

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

		Form				&operator=(const Form &other);

};

std::ostream& 				operator<<(std::ostream& streamRef,const Form& form);

#endif