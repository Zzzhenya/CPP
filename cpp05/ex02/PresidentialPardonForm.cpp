#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", PRES_SIGN, PRES_EXEC)
{
	this->_target = "Default";
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

const std::string &PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &bcat)
{
	try
	{
		AForm::beSigned(bcat);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << getTarget();
		std::cout << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}