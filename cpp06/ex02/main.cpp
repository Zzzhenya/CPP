/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:20:13 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/27 21:07:39 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "X.hpp"

#ifdef _DEBUG
#define debug(x) ((x))
#else
#define debug(x)
#endif

/**
 * It randomly instanciates A, B or C and 
 * returns the instance as a Base pointer. 
 * Feel free to use anything you like for the random choice implementation.
**/
Base *generate(void)
{
	Base *ret = NULL;
 	switch(rand()%3)
 	{
 		case 0:
 			ret = new A();
 			break;
 		case 1:
 			ret = new B();
 			break;
 		case 2:
 			ret = new C();
 			break;
 	}
	return (ret);
}

/**
 *It prints the actual type of the object pointed to by p: 
 *"A", "B" or "C".
**/
void identify(Base* p)
{
	if (dynamic_cast <A *> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast <B *> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast <C *> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

/**
 * It prints the actual type of the object pointed to by p:
 * "A", "B" or "C". 
 * Using a pointer inside this function is forbidden.
**/
void identify(Base& p)
{
	try 
	{
		A a = dynamic_cast <A&> (p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
		debug(std::cerr << "A::" << e.what() << std::endl);
	}
	try
	{
		B b = dynamic_cast <B&> (p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
		debug(std::cerr << "B::" << e.what() << std::endl);
	}
	try 
	{
		C c = dynamic_cast <C&> (p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::exception &e)
	{
		debug(std::cerr << "C::" << e.what() << std::endl);
	}
	std::cout << "Unknown" << std::endl;
	return;
}

void	main_program(void)
{
	Base *ret = NULL;
	ret = generate();
	if (ret)
	{
		identify(ret);
		identify(*ret);
		delete ret;
	}
	else
		std::cerr << "NULL ptr" << std::endl;	
}

void null_test(void)
{
	Base *ret = NULL;
	if (ret)
	{
		identify(ret);
		identify(*ret);
		delete ret;
	}
	else
		std::cerr << "NULL ptr" << std::endl;
}

void other_object_test(void)
{
	Base *ret = new X();
	if (ret)
	{
		identify(ret);
		identify(*ret);
		delete ret;
	}
	else
		std::cerr << "NULL ptr" << std::endl;
}

void repeat_test(void)
{
	for (int i = 0; i < 20; i++)
		main_program();	
}

//Including the typeinfo header is forbidden.
int main (void)
{
	std::srand(std::time(0));

	std::cout << "=========== main program ================"  << std::endl;
	main_program();
	std::cout << "=========== null test ===================" << std::endl;
	null_test();
	std::cout << "=========== other object test ===========" << std::endl;
	other_object_test();
	// repeat_test();
	return (0);
}
