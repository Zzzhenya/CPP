/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:51:35 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/17 15:26:46 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Creates a zombie, name it, 
	and return it so you can use it outside 
	of the function scope.
*/
Zombie* newZombie( std::string name )
{
	Zombie *newZombie = NULL;

	newZombie = new Zombie(name);
	return (newZombie);
}
