#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	AForm	*form = new ShrubberyCreationForm();
	AForm 	*form1 = new RobotomyRequestForm();
	AForm 	*form2 = new PresidentialPardonForm();

	std::cout << *form;
	std::cout << *form1;
	std::cout << *form2;

	delete form;
	delete form1;
	delete form2;
	return (0);
}