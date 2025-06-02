/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:35:57 by sde-silv          #+#    #+#             */
/*   Updated: 2025/03/06 19:39:39 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>
#define BASIC 0
#define SIGN 1
#define PASS 1
#define FAIL 0

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

void	test_case(std::string test, int sign, int exec, int type, Bureaucrat bcat, int result)
{
	std::cout << test << std::endl;
	LB;
	if (type == BASIC)
	{
		if (unit(bcat, "Form1", sign, exec, basic_form) != result)
			std::cout << "\033[43m\t\t Error\033[00m" << std::endl;
	}
	else
	{
		if (unit(bcat, "Form1", 2, 3, basic_sign_form) != result)
			std::cout << "\033[43m\t\t Error\033[00m" << std::endl;
	}
}

void	bcat_grade_vs_form_grade(void)
{
	Bureaucrat b = Bureaucrat("Bob", 1);
	test_case("Sign: High enough to sign", 2, 3, SIGN, b, PASS);
	b.downGrade();
	test_case("Sign: Marginally high enough to sign", 2, 3, SIGN, b, PASS);
	b.downGrade();
	test_case("Sign: Not high enough to sign", 2, 3, SIGN, b, FAIL);
}

void	form_grades(void)
{
	test_case("Form: Normal form", 2, 3, BASIC, Bureaucrat(), PASS);
	test_case("Form: Too high sign grade", -1, 3, BASIC, Bureaucrat(), FAIL);
	test_case("Form: Too high exec grade", 3, -1, BASIC, Bureaucrat(), FAIL);
	test_case("Form: Too high sign and exec grade" , 0, 0, BASIC, Bureaucrat(), FAIL);
	test_case("Form: Too low sign grade" , 151, 2, BASIC, Bureaucrat(), FAIL);
	test_case("Form: Too low exec grade" , 150, 154, BASIC, Bureaucrat(), FAIL);
	test_case("Form: Too low exec grade" , 2144, 3418, BASIC, Bureaucrat(), FAIL);
}

int main(void)
{
	form_grades();
	bcat_grade_vs_form_grade();
	return (0);
}
