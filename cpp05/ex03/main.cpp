/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:14:02 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/06 00:42:03 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat bcat = Bureaucrat("Bob", 2);
	{
		AForm *ret = intern.makeForm("ShrubberyCreationForm", "home");
		if (ret)
			std::cout << *ret;
		if (ret)
			ret->beSigned(bcat);
		if (ret)
			std::cout << *ret;
		if (ret)
			delete ret;
	}
	{
		AForm *ret = intern.makeForm("Blahblah", "home");
		if (ret)
			std::cout << *ret;
		if (ret)
			ret->beSigned(bcat);
		if (ret)
			std::cout << *ret;
		if (ret)
			delete ret;	
	}
	{
		AForm *ret = intern.makeForm("RobotomyRequestForm", "home");
		if (ret)
			std::cout << *ret;
		if (ret)
			ret->beSigned(bcat);
		if (ret)
			std::cout << *ret;
		if (ret)
			delete ret;	
	}
	{
		AForm *ret = intern.makeForm("PresidentialPardonForm", "home");
		if (ret)
			std::cout << *ret;
		if (ret)
			ret->beSigned(bcat);
		if (ret)
			std::cout << *ret;
		if (ret)
			delete ret;	
	}

	{
    	Intern  someRandomIntern;
    	AForm*   rrf;
    	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    	std::cout << *rrf;
    	delete rrf;
	}
	return (0);
}