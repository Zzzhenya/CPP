#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

# define SHRUB_SIGN 145
# define SHRUB_EXEC 137

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(std::string target);

		const std::string 		&getTarget(void) const;

		void					beSigned(const Bureaucrat &bcat);
		void					execute(Bureaucrat const & executor) const;

	private:
		std::string 			_target;
};

std::ostream& 					operator<<(std::ostream& streamRef,const ShrubberyCreationForm& form);

#endif