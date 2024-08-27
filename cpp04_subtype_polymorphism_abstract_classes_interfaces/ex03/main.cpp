/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:47 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 14:00:48 by sde-silv         ###   ########.fr       */
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

void materia_tests(void)
{
	{
		ICharacter *ch1 = new Character("BoB");
		AMateria *i1 = new Ice();
		AMateria *c1 = new Cure();
		std::cout << i1->getType() << std::endl;
		i1->use(*ch1);
		std::cout << c1->getType() << std::endl;
		c1->use(*ch1);
		delete i1;
		delete c1;
		delete ch1;
	}
	{
		ICharacter *ch1 = new Character("Jane");
		AMateria *am1 = NULL;
		Ice i1;
		am1 = &i1;

		std::cout << am1->getType() << std::endl;
		std::cout << i1.getType() << std::endl;
		am1->use(*ch1);

		delete ch1;
	}
}

int main (void)
{

	//subject_tests();
	materia_tests();
	return (0);
}