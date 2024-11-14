/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:06:15 by sde-silv          #+#    #+#             */
/*   Updated: 2024/11/14 22:31:18 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Form(std::string name, unsigned int sign_grade, unsigned int exec_grade);

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