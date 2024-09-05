/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:07:36 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/05 16:07:57 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):_name("default"),_signed(0),
	_sign_grade(HIGHEST_GRADE),_exec_grade(LOWEST_GRADE)
{
	debug(std::cout << "Form default constructor\n");
}

Form::Form(const Form &other):_name(other._name),_signed(0),
	_sign_grade(other._sign_grade),_exec_grade(other._exec_grade)
{
	debug(std::cout << "Form copy constructor\n");
}

/*
	Cannot copy assing _name, _sign_grade and _exec_grade - const
	Copy assignment non-functional, therefore private
*/
Form	&Form::operator=(const Form &other)
{
	this->_signed = other._signed;
	debug(std::cout << "Form copy assignment operator overload\n");
	return (*this);
}

Form::Form(std::string name, int sign_grade, int exec_grade):_name(name),
	_signed(0),_sign_grade(sign_grade),_exec_grade(exec_grade)
{
	if (sign_grade > LOWEST_GRADE || exec_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (sign_grade < HIGHEST_GRADE || exec_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	debug(std::cout << "Form constructor\n");
}

Form::~Form(void)
{
	debug(std::cout << "Form destructor\n");
}

bool	Form::getStatus(void) const
{
	return (this->_signed);
}

std::string 	Form::getName(void) const
{
	return(this->_name);
}

unsigned int 	Form::getSignGrade(void) const
{
	return(this->_sign_grade);
}

unsigned int 	Form::getExecGrade(void) const
{
	return(this->_exec_grade);
}

void	Form::setStatus(bool status)
{
	if (this->_signed != status)
		this->_signed = status;
}

void Form::beSigned(const Bureaucrat &bcat)
{
	unsigned int bcatgrade = bcat.getGrade();
	if (bcatgrade > getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (bcatgrade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	bcat.signForm(this);
}


std::ostream& operator<<(std::ostream& streamRef,const Form& form)
{
	streamRef << form.getName() << " \t\t: ";
	if (form.getStatus())
		streamRef << "Signed";
	else
		streamRef << "Unsigned";
	streamRef << "\tS: " << form.getSignGrade();
	streamRef << "  E: " << form.getExecGrade() << std::endl;
	return (streamRef);
}
