/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:56:53 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:06:47 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

# define ROBO_SIGN 72
# define ROBO_EXEC 45

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm		&operator=(const RobotomyRequestForm &other);

		RobotomyRequestForm(std::string target);

		const std::string 		&getTarget(void) const;

		void					beSigned(const Bureaucrat &bcat);
		void					execute(Bureaucrat const & executor) const;

	private:
		std::string				_target;

};

std::ostream& 					operator<<(std::ostream& streamRef,const RobotomyRequestForm& form);

#endif