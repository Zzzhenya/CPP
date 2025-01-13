/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:35:57 by sde-silv          #+#    #+#             */
/*   Updated: 2024/12/29 18:19:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>
#define BASIC 0
#define SIGN 1

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

void	test_case(std::string test, int sign, int exec, int type, Bureaucrat bcat)
{
	std::cout << test << std::endl;
	LB;
	if (type == BASIC)
	{
		if (!unit(bcat, "Form1", sign, exec, basic_form))
			std::cout << "\t\t Error" << std::endl;
	}
	else
	{
		if (!unit(bcat, "Form1", 2, 3, basic_sign_form))
			std::cout << "\t\t Error" << std::endl;
	}
}

void	bcat_grade_vs_form_grade(void)
{
	Bureaucrat b = Bureaucrat("Bob", 1);
	test_case("Sign: High enough to sign", 2, 3, SIGN, b);
	b.downGrade();
	test_case("Sign: Marginally high enough to sign", 2, 3, SIGN, b);
	b.downGrade();
	test_case("Sign: Not high enough to sign", 2, 3, SIGN, b);
}

void	form_grades(void)
{
	test_case("Form: Normal form", 2, 3, BASIC, Bureaucrat());
	test_case("Form: Too high sign grade", -1, 3, BASIC, Bureaucrat());
	test_case("Form: Too high exec grade", 3, -1, BASIC, Bureaucrat());
	test_case("Form: Too high sign and exec grade" , 0, 0, BASIC, Bureaucrat());
	test_case("Form: Too low sign grade" , 151, 2, BASIC, Bureaucrat());
	test_case("Form: Too low exec grade" , 150, 154, BASIC, Bureaucrat());
	test_case("Form: Too low exec grade" , 2144, 3418, BASIC, Bureaucrat());
}

void form_unittests(void)
{
	Form a;
	std::cout << a << std::endl;
}

#include <vector>

int main(void)
{
	std::vector<int> v;
	v.push_back(4);
	std::cout << &v;
	// form_unittests();
	// form_grades();
	// bcat_grade_vs_form_grade();
	return (0);
}