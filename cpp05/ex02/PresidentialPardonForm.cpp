#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXEC)
{
	this->_target = ".";
	debug(std::cout << "Presidential default constructor\n");
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	debug(std::cout << "Presidential destructor\n");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXEC)
{
	this->_target = target;
	debug(std::cout << "Presidential constructor\n");
}