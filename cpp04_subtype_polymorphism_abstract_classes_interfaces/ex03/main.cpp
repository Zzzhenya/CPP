/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:47 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/26 14:07:43 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void draw_seperator(void)
{
	std::cout << "===================================\n";
}

// void amateria_tests_before_abstraction(void)
// {
// 	draw_seperator();
// 	{
// 		AMateria abc("one");

// 		std::cout << "Type: " << abc.getType() << std::endl;
// 	}
// 	draw_seperator();
// 	{
// 		AMateria one;
// 		AMateria *two = NULL;

// 		std::cout << "Type: " << one.getType() << std::endl;
// 		two = one.clone();
// 		std::cout << "Type: " << two->getType() << std::endl;

// 		delete two;
// 	}	
// }

void ice_tests_berfore_abstraction(void)
{
	draw_seperator();
	{
		Ice one;
		std::cout << "Type: " << one.getType() << std::endl;
	}
	draw_seperator();
	{
		Cure one;
		std::cout << "Type: " << one.getType() << std::endl;		
	}
	draw_seperator();
	{
		Ice one;
		AMateria *two = NULL;

		std::cout << "Type: " << one.getType() << std::endl;
		two = one.clone();
		std::cout << "Type: " << two->getType() << std::endl;

		delete two;
	}
	draw_seperator();
	{
		Cure one;
		AMateria *two = NULL;

		std::cout << "Type: " << one.getType() << std::endl;
		two = one.clone();
		std::cout << "Type: " << two->getType() << std::endl;

		delete two;
	}
}

void cure_ice_after_abs(void)
{
	Character *one = new Character("Hello");
	Character *two = new Character("World");
	Cure c1;
	Ice i1;
	Cure c2;
	Cure c3;
	Ice i2;
	
	one->equip(&c1);
	one->equip(&i1);
	one->equip(&c2);
	one->equip(&c3);
	// one->equip(&i2);
	one->use(0, *two);
	one->use(1, *two);
	one->use(2, *two);
	// one->use(3, *two);
	// // one->equip(&c1);
	// one->use(0, *two);

	delete one;
	delete two;
}

void subject_tests(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void check_clone_calls_copy_constructor(void)
{
	Cure c1;
	AMateria *c2;

	c2 = c1.clone();
	// *c2 = c1;
	std::cout << c2->getType() << std::endl;
	delete c2;
}

int main (void)
{
	// amateria_tests_before_abstraction();
	// ice_tests_berfore_abstraction();
	// cure_ice_after_abs();

	subject_tests();
	// check_clone_calls_copy_constructor();

	return (0);
}