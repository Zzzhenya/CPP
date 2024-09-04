#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXEC)
{
	this->_target = "Default";
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

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &bcat)
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
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << "Drrrrrr.... \nrrr... \ndrrrrrrr....\n";
	std::srand(std::time(0));
	int num = std::rand() % 2;
	if (num)
		std::cout << getTarget() << " has been robotomized successfully\n";
	else
		std::cout << getTarget() << " robotomy failed\n";
}