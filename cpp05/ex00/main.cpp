/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:59:17 by sde-silv          #+#    #+#             */
/*   Updated: 2024/12/27 00:45:16 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#define STACK 'S'
#define HEAP 'H'
#define LB std::cerr << "=======================================\n"

void	basic_stack(std::string name, int val)
{
	Bureaucrat b1;

	if (name.length() > 0)
	{
		std::string nme = std::string(name);
		Bureaucrat b1 = Bureaucrat(nme, val);
	}
	else
		Bureaucrat b1;
	std::cout << b1;
}

void	basic_heap(std::string name, int val)
{
	Bureaucrat *b1 = NULL;

	if (name.length() > 0)
	{
		std::string nme = std::string(name);
		b1 = new Bureaucrat(nme, val);
	}
	else
		b1 = new Bureaucrat();
	std::cout << *b1;
	delete b1;
}

void	try_make_b(std::string name, int grade, char type)
{
	try
	{
		if (type == STACK)
			basic_stack(name, grade);
		else if (type == HEAP)
			basic_heap(name, grade);
	}
	catch (std::exception & e)
	{
		if (grade < HIGHEST_GRADE && std::string(e.what()) == E_TOO_HIGH)
			std::cerr << e.what() << std::endl;
		else if (grade > LOWEST_GRADE && std::string(e.what()) == E_TOO_LOW)
			std::cerr << e.what() << std::endl;
		else
			std::cerr << "ERROR " << grade << " " << e.what() << std::endl;	
	}
	LB;
}

void	simple_tests(void)
{
	std::cout << "Basic tests." << std::endl;
	try_make_b("", 0, STACK);
	try_make_b("", 1, STACK);
	try_make_b("", 0, HEAP);
	try_make_b("", 1, HEAP);
	std::cout << "Stack\n";
	try_make_b("Bob", 0, STACK);
	try_make_b("Bob", 1, STACK);
	try_make_b("Bob", 9, STACK);
	try_make_b("Bob", 150, STACK);
	try_make_b("Bob", 400, STACK);
	try_make_b("Bob", -10, STACK);
	std::cout << "Heap\n";
	try_make_b("Bob", 0, HEAP);
	try_make_b("Bob", 1, HEAP);
	try_make_b("Bob", 9, HEAP);
	try_make_b("Bob", 150, STACK);
	try_make_b("Bob", 400, HEAP);
	try_make_b("Bob", -10, HEAP);
}

void	combination_test(void)
{
	{
		try
		{
			Bureaucrat b1 = Bureaucrat("Bob", 1);
			for (int i = 0; i < 500; i++)
			{
				if (b1.getGrade() % 10 == 0)
					std::cout << b1;
				b1.downGrade();
			}
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_LOW)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
		LB;
	}
	{
		try
		{
			Bureaucrat b1 = Bureaucrat("Bob", 150);
			for (int i = 0; i < 500; i++)
			{
				if (b1.getGrade() % 10 == 0 || b1.getGrade() < 10)
					std::cout << b1;
				b1.upGrade();
			}
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
		LB;
	}
}

int main(void)
{
	simple_tests();
	combination_test();
	return (0);
}
