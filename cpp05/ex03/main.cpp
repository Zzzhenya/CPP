/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:14:02 by sde-silv          #+#    #+#             */
/*   Updated: 2025/03/06 20:09:46 by sde-silv         ###   ########.fr       */
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
		{
			std::cout << *ret;
			ret->beSigned(bcat);
			std::cout << *ret;
			ret->execute(bcat);
			std::cout << *ret;
			delete ret;
		}
	}
	{
		AForm *ret = intern.makeForm("Blahblah", "abc");
		if (ret)
		{
			std::cout << *ret;
			ret->beSigned(bcat);
			std::cout << *ret;
			ret->execute(bcat);
			std::cout << *ret;
			delete ret;
		}
	}
	{
		AForm *ret = intern.makeForm("RobotomyRequestForm", "cde");
		if (ret)
		{
			std::cout << *ret;
			ret->beSigned(bcat);
			std::cout << *ret;
			ret->execute(bcat);
			std::cout << *ret;
			delete ret;
		}
	}
	{
		AForm *ret = intern.makeForm("PresidentialPardonForm", "efg");
		if (ret)
		{
			std::cout << *ret;
			ret->beSigned(bcat);
			std::cout << *ret;
			ret->execute(bcat);
			std::cout << *ret;
			delete ret;
		}	
	}

	{
    	Intern  someRandomIntern;
    	AForm*   rrf;
    	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    	std::cout << *rrf;
    	delete rrf;
	}
	{
    	Intern  someRandomIntern;
    	RobotomyRequestForm*   rrf;
    	rrf = (RobotomyRequestForm *)someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    	std::cout << *rrf;
    	delete rrf;	
	}
	return (0);
}