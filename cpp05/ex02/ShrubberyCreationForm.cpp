#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC)
{
	this->_target = ".";
	debug(std::cout << "Shrubbery default constructor\n");
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	debug(std::cout << "Shrubbery destructor\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC)
{
	this->_target = target;
	debug(std::cout << "Shrubbery constructor\n");
}