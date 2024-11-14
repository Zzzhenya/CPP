/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:35:57 by sde-silv          #+#    #+#             */
/*   Updated: 2024/11/14 22:35:01 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>

#define LB std::cout << "===================================" << std::endl;

void	basic_sign_form(Bureaucrat b, std::string name, int sign, int exec)
{
	Form a(name, sign, exec);
	std::cout << a;
	a.beSigned(b);
	std::cout << a;
}

void	basic_form(Bureaucrat b, std::string name, int sign, int exec)
{
	(void)b;
	Form a(name, sign, exec);
	std::cout << a;
}

int	unit(Bureaucrat b, std::string name, int sign, int exec, void (*func)(Bureaucrat, std::string, int, int))
{
	LB;
	try
	{
		func(b, name, sign, exec);
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}

void	bcat_grade_vs_form_grade(void)
{
	Bureaucrat b = Bureaucrat("Bob", 1);
	LB;
	std::cout << "High enough to sign" << std::endl;
	
	unit(b, "Form1", 2, 3, basic_sign_form);
	b.downGrade();
	LB;

	std::cout << "Marginally high enough to sign" << std::endl;
	unit(b, "Form2", 2, 3, basic_sign_form);
	b.downGrade();
	LB;
	
	std::cout << "Not high enough to sign" << std::endl;
	unit(b, "Form3", 2, 3, basic_sign_form);
}

void	form_grades(void)
{
	{
		std::cout << "Form: Normal form" << std::endl;
		
		if (!unit(Bureaucrat(), "Form1", 2, 3, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too high sign grade" << std::endl;

		if (unit(Bureaucrat(), "Form1", -1, 3, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too high exec grade" << std::endl;
		
		if (unit(Bureaucrat(), "Form1", 3, -1, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too high sign and exec grade" << std::endl;

		if (unit(Bureaucrat(), "Form1", 0, 0, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too low sign grade" << std::endl;
	
		if (unit(Bureaucrat(), "Form1", 151, 2, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too low exec grade" << std::endl;
		if (unit(Bureaucrat(), "Form1", 150, 154, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Too low sign and exec grade" << std::endl;

		if (unit(Bureaucrat(), "Form1", 2144, 3418, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
}

void	int_min_max(void)
{
	{
		std::cout << "Form: Int min" << INT_MIN << std::endl;
	
		if (unit(Bureaucrat(), "Form1", INT_MIN, 2, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	{
		std::cout << "Form: Uint max" << UINT_MAX << std::endl;
	
		if (unit(Bureaucrat(), "Form1", UINT_MAX + 1, 2, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
}

int main(void)
{
	form_grades();
	bcat_grade_vs_form_grade();
	int_min_max();
	return (0);
}