/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:05:15 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:05:33 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

# define PRES_SIGN 25
# define PRES_EXEC 5

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		
		PresidentialPardonForm(std::string target);

		const std::string 		&getTarget(void) const;

		void					beSigned(const Bureaucrat &bcat);
		void					execute(Bureaucrat const & executor) const;

	private:
		std::string 			_target;

};

std::ostream& 				operator<<(std::ostream& streamRef,const PresidentialPardonForm& form);

#endif