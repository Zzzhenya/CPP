#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

void basic(void)
{
	AForm	*form = new ShrubberyCreationForm("home");
	Bureaucrat b1 = Bureaucrat("Bob", 2);
	// AForm 	*form1 = new RobotomyRequestForm();
	// AForm 	*form2 = new PresidentialPardonForm();

	std::cout << *form;
	form->beSigned(b1);
	std::cout << *form;
	form->execute(b1);
	std::cout << *form;
	// std::cout << *form1;
	// std::cout << *form2;

	delete form;
	// delete form1;
	// delete form2;
}

int main(void)
{
	basic();
	//AForm form;
	return (0);
}