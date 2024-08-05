/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:22:45 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/05 15:25:27 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap b("One");
	ClapTrap a("Two");

	a.print_score();
	b.print_score();
	for(int i = 0; i < 20; i++)
	{
		if (!(i%4))
			b.beRepaired(i);
		else
		{
			b.attack("Two");
			a.takeDamage(b.getAttackDamage());
		}
		a.print_score();
		b.print_score();
	}
	return (0);
}