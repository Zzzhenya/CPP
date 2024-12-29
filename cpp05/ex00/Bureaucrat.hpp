/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:11:13 by sde-silv          #+#    #+#             */
/*   Updated: 2024/12/29 16:32:11 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1
# define E_TOO_LOW "\033[1;31mException: Grade too low\033[0m"
# define E_TOO_HIGH "\033[1;31mException: Grade too high\033[0m"

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
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(std::string name, int grade);

		const std::string		&getName(void) const;
		const unsigned int		&getGrade(void) const;
		void					upGrade(void);
		void					downGrade(void);

	private:
		const std::string		_name;
		unsigned int			_grade;

		void					setGrade(unsigned int new_grade);
		Bureaucrat				&operator=(const Bureaucrat &other);
	
};

std::ostream& operator<<(std::ostream& streamRef,const Bureaucrat& bcat);

#endif