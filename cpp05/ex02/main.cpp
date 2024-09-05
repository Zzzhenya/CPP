/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:14:02 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:06:14 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void basic(void)
{
	Bureaucrat b1 = Bureaucrat("Bob", 2);

	{
		AForm	*form = new ShrubberyCreationForm("home");
		std::cout << *form;
		form->beSigned(b1);
		std::cout << *form;
		form->execute(b1);
		std::cout << *form;
		delete form;
	}
	{
		AForm 	*form = new RobotomyRequestForm("target_one");
		std::cout << *form;
		form->beSigned(b1);
		std::cout << *form;
		form->execute(b1);
		std::cout << *form;
		delete form;
	}
	{
		AForm 	*form = new PresidentialPardonForm("Tom");
		std::cout << *form;
		form->beSigned(b1);
		std::cout << *form;
		form->execute(b1);
		std::cout << *form;
		delete form;
	}

}

int main(void)
{
	// basic();
	//AForm form;

	// copy constructor
	// PresidentialPardonForm one = PresidentialPardonForm("bin");
	// PresidentialPardonForm two = PresidentialPardonForm(one);

	PresidentialPardonForm one = PresidentialPardonForm("bin");
	PresidentialPardonForm two = PresidentialPardonForm("home");
	Bureaucrat bcat = Bureaucrat("Tom", 2);

	two.beSigned(bcat);
	std::cout << one;
	std::cout << two;


	one = two;

	std::cout << one;
	std::cout << two;
	return (0);
}