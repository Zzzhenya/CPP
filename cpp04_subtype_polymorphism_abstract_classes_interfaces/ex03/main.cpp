/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:47 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 17:33:47 by sde-silv         ###   ########.fr       */
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
	AMateria *i1 = new Ice();
	AMateria *c1 = new Cure();
	src->learnMateria(i1);
	src->learnMateria(c1);
	ICharacter* me = new Character("me");
	AMateria* tmp = NULL;
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
	delete i1;
	delete c1;
}
void materia_tests(void)
{
	draw_seperator();
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
	draw_seperator();
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
	draw_seperator();
}

void materia_source_tests(void)
{
	draw_seperator();
	{
		IMateriaSource *src1 = new MateriaSource();
		MateriaSource src2;
		
		//(*src1).print_source();
		src2.print_source();

		(void)src1;
		delete src1;
	}
	draw_seperator();
	{
		IMateriaSource* src = new MateriaSource();
		Ice i1;
		Cure c1;
		src->learnMateria(&i1);
		src->learnMateria(&c1);
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

}

int main (void)
{
	subject_tests();
	materia_source_tests();
	// materia_tests();
	
	return (0);
}