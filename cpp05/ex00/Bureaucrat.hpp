#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);

		const std::string		&getName(void) const;
		const unsigned int		&getGrade(void) const;

	private:
		const std::string	_name;
		unsigned int		_grade;
	
};

#endif