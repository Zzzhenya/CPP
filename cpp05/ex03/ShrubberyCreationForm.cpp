/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:13 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/09 19:59:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC)
{
	this->_target = "Default";
	debug(std::cout << "Shrubbery default constructor\n");
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	debug(std::cout << "Shrubbery destructor\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other)
{
	this->_target = other._target;
	debug(std::cout << "Shrubbery copy constructor\n");
}

// Not copying the status, only target
// this->setStatus(other.getStatus());
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	debug(std::cout << "Shrubbery copy assignment operator overload\n");
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC)
{
	this->_target = target;
	debug(std::cout << "Shrubbery constructor\n");
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &bcat)
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

void	draw_tree(std::fstream &outfile, int num)
{
	int k = 0;
	int l = num;
	for (int i = 0; i < num; i++)
	{
		for (int i = 0; i < l; i++)
		{
			if (num > 5)
			{
				if (l%2 && i == 0)
					outfile << "  ";
			}
			outfile << " ";
		}
		for (int i = k; i > 0; i --)
			outfile << "*";
		for (int i = k; i > 0; i --)
		{
			if (i > 1)
				outfile << "*";
		}
		k++;
		l--;
	 	outfile << std::endl;
	}
	for (int i = 0; i < num/2; i++)
	{
		for (int i = 0; i < (num*9)/10 + 1; i++)
			outfile << " ";
		for (int i = 0; i < num/4; i++)
			outfile << "*";
		outfile << std::endl;
	}
}

void 	draw_shrubs(std::fstream &outfile)
{
	std::srand(std::time(0));
	draw_tree(outfile, std::rand() % 50 + 5);
}

/**
 * You have to check that the form is signed and 
 * that the grade of the bureaucrat attempting to 
 * execute the form is high enough. 
 * Otherwise, throw an appropriate exception.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	std::string outfile_name = std::string(getTarget()) + std::string("_shrubbery");
	try
	{
		std::fstream outfile ((const char *)outfile_name.c_str(), std::ios::out | std::ios::trunc);
		outfile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
		draw_shrubs(outfile);
		outfile.close();
	}
	catch(const std::ios_base::failure& fail)
	{
		std::cerr << "failed to create and open " << outfile_name.c_str() << std::endl;
		debug(std::cerr << fail.what() << std::endl);
		return;
	}
	std::cout << "Successfully created " << outfile_name.c_str() << std::endl;
}

std::ostream& operator<<(std::ostream& streamRef,const ShrubberyCreationForm& form)
{
	streamRef << *(AForm*)&form;
	streamRef << "\t\t\t\t\ttarget: " << form.getTarget() << std::endl;
	return (streamRef);
}