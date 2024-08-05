/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:50 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/05 16:14:51 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	clap_trap_test(void)
{
	ClapTrap b("ONE");
	ClapTrap a("TWO");

	a.print_score();
	b.print_score();
	for(int i = 0; i < 5; i++)
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
}

void	scav_trap_test(void)
{
	ScavTrap a("THREE");
	ScavTrap b("FOUR");

	a.print_score();
	b.print_score();
	
	for(int i = 0; i < 5; i++)
	{
		if (!(i%4))
		{
			a.guardGate();
			b.beRepaired(i+1);
		}
		else if (!(i%3))
		{
			b.attack("Scav_AA");
			a.takeDamage(b.getAttackDamage());
		}
		else
		{
			a.attack("Scav_BB");
			b.takeDamage(b.getAttackDamage());
		}
		a.print_score();
		b.print_score();
	}
}

int main (void)
{
	std::cout << std::endl << "=====ClapTrap tests:=====" << std::endl << std::endl;
	clap_trap_test();
	std::cout << std::endl << "=====ScavTrap tests:=====" << std::endl << std::endl;
	scav_trap_test();
	return (0);
}