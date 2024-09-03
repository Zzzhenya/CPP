#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1
# define E_TOO_LOW "Exception: Grade too low"
# define E_TOO_HIGH "Exception: Grade too high"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

class Exceptions
{
	public:
		class GradeTooHighException: public std::exception 
		{
			public:
				virtual const char * what() const throw()
				{
	    			return (E_TOO_HIGH);
	    		}
		};

		class GradeTooLowException: public std::exception 
		{
			public:
				virtual const char * what() const throw()
				{
	    			return (E_TOO_LOW);
				}
		};
};

class Bureaucrat: public Exceptions
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);

		const std::string		&getName(void) const;
		const unsigned int		&getGrade(void) const;
		void					upGrade(int val);
		void					downGrade(int val);


	private:
		const std::string		_name;
		unsigned int			_grade;

		void					setGrade(unsigned int new_grade);
	
};

#endif