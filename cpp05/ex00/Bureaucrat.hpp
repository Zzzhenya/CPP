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

class MyExceptions
{
	public:
		class GradeTooHighException: public std::exception 
		{
			public:
				virtual const char * what() const throw()
				{
	    			return ("Grade too high");
	    		}
		};

		class GradeTooLowException: public std::exception 
		{
			public:
				virtual const char * what() const throw()
				{
	    			return ("Grade too low");
				}
		};
};

class Bureaucrat : public MyExceptions
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);

		const std::string		&getName(void) const;
		const unsigned int		&getGrade(void) const;
		void					setGrade(unsigned int new_grade);
		void					upGrade(unsigned int val);
		void					downGrade(unsigned int val);

		// class GradeTooHighException: public std::exception 
		// {
    	// 	public:
		// 		virtual const char * what() const throw()
		// 		{
        // 			return ("Grade too high");
    	// 		}
		// };

		// class GradeTooLowException: public std::exception 
		// {
    	// 	public:
		// 		virtual const char * what() const throw()
		// 		{
        // 			return ("Grade too low");
    	// 		}
		// };

	private:
		const std::string	_name;
		unsigned int		_grade;
	
};

#endif