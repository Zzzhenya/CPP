/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:05:15 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:06:42 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other)
{
	this->_target = other._target;
	debug(std::cout << "Robotomy copy constructor\n");
}

// Not copying the status, only target
// this->setStatus(other.getStatus());
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	debug(std::cout << "Robotomy copy assignment operator overload\n");
	return (*this);
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

std::ostream& operator<<(std::ostream& streamRef,const RobotomyRequestForm& form)
{
	streamRef << *(AForm*)&form;
	streamRef << "\t\t\t\t\ttarget: " << form.getTarget() << std::endl;
	return (streamRef);
}
