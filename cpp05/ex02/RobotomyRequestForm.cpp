#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXEC)
{
	this->_target = ".";
	debug(std::cout << "Robotomy default constructor\n");
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	debug(std::cout << "Robotomy destructor\n");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXEC)
{
	this->_target = target;
	debug(std::cout << "Robotomy constructor\n");
}