/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:43:36 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:05:58 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual ~AForm(void);
		AForm(const AForm &other);
		AForm(std::string name, int sign_grade, int exec_grade);

		bool				getStatus(void) const;
		std::string 		getName(void) const;
		unsigned int 		getSignGrade(void) const;
		unsigned int 		getExecGrade(void) const;
		void				setStatus(bool status);

		virtual void		beSigned(const Bureaucrat &bcat) = 0;
		virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int 	_sign_grade;
		const unsigned int 	_exec_grade;

		AForm				&operator=(const AForm &other);

};

std::ostream& 				operator<<(std::ostream& streamRef,const AForm& form);

#endif