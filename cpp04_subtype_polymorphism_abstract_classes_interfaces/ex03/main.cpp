/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:47 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/23 17:55:06 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "LinkedList.hpp"
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

void	equip_use_tests_after_abs(void)
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

void linkedlist_tests(void)
{
	AMateria *c1 = new Cure();
	AMateria *i1 = new Ice();
	LinkedList lst;

	lst.insertNode(c1);
	lst.insertNode(i1);

	lst.printList();

	delete c1;
	delete i1;
	lst.printList();

}

int main (void)
{
	// amateria_tests_before_abstraction();
	// ice_tests_berfore_abstraction();
	equip_use_tests_after_abs();

	// linkedlist_tests();


	return (0);
}