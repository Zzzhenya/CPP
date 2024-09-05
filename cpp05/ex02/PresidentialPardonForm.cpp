/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:51:33 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:06:36 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other)
{
	this->_target = other._target;
	debug(std::cout << "Presidential copy constructor\n");
}

// Not copying the status, only target
// this->setStatus(other.getStatus());
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->_target = other._target;
	debug(std::cout << "Presidential copy assignment operator overload\n");
	return (*this);
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

std::ostream& operator<<(std::ostream& streamRef,const PresidentialPardonForm& form)
{
	streamRef << *(AForm*)&form;
	streamRef << "\t\t\t\t\ttarget: " << form.getTarget() << std::endl;
	return (streamRef);
}