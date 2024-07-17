/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:14:21 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/17 15:14:59 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * RandomChump in stack
*/
void	randomChump(std::string name)
{
	Zombie Chump = Zombie(name);
	Chump.announce();
}
/*
	RandomChump in heap;

void randomChump( std::string name )
{
	Zombie *randomChump;

	randomChump = new Zombie(name);
	randomChump->announce();
	delete randomChump;
}
*/
