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
	basic();
	//AForm form;
	return (0);
}