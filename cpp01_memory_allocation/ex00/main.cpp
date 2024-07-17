/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:49:32 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/17 15:26:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/* 
 * Create zombies with public Zombie(name) constructor

void	stack_zombies(void)
{
	std::cout << "\n\tStack Zombies..\n" << std::endl;

	Zombie zombstack = Zombie("Stacky1");
	zombstack.announce();
	Zombie zombstack1 = Zombie("Stacky2");
	zombstack1.announce();
}
stack_zombies();
*/
int main(void)
{
	Zombie *zomb1 = NULL;
	Zombie *zomb2 = NULL;
	Zombie *zomb3 = NULL;

	std::cout << "\n\tHeap Zombies..\n" << std::endl;

	zomb1 = newZombie("Aaaaa");
	zomb1->announce();
	zomb2 = newZombie("Baaaa");
	zomb2->announce();
	zomb3 = newZombie("Caaaa");
	zomb3->announce();

	std::cout << "\nDeleting.." << std::endl;

	delete zomb1;
	delete zomb2;
	delete zomb3;

	std::cout << "\n\tRandom chumps in stack.\n" << std::endl;

	randomChump("Rando 1");
	randomChump("Rando 2");
	randomChump("Rando 42");
	
	return (0);
}
