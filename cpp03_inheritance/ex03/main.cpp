/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:14:50 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 19:26:49 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
			b.attack("TWO");
			a.takeDamage(b.getAttackDamage());
		}
		a.print_score();
		b.print_score();
	}
}

void	scav_trap_test(void)
{
	ScavTrap a("Scav_AA");
	ScavTrap b("Scav_BB");

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

void	frag_trap_test(void)
{
	FragTrap a("X");
	FragTrap b("Y");

	a.print_score();
	b.print_score();
	
	for(int i = 0; i < 5; i++)
	{
		if (!(i%4))
		{
			a.highFivesGuys();
			b.beRepaired(i+1);
		}
		else if (!(i%3))
		{
			b.attack("X");
			a.takeDamage(b.getAttackDamage());
		}
		else
		{
			a.attack("Y");
			b.takeDamage(b.getAttackDamage());
		}
		a.print_score();
		b.print_score();
	}
}

void	diamond_trap_test(void)
{
	DiamondTrap a("X");
	DiamondTrap b("Y");

	a.print_score();
	b.print_score();
	
	a.whoAmI();
	b.whoAmI();
	for(int i = 0; i < 5; i++)
	{
		if (!(i%4))
		{
			b.beRepaired(i+1);
		}
		else if (!(i%3))
		{
			b.attack("X");
			a.takeDamage(b.getAttackDamage());
		}
		else
		{
			a.attack("Y");
			b.takeDamage(b.getAttackDamage());
		}
		a.print_score();
		b.print_score();
	}
}

void	diamond_trap_base_test(void)
{
	{
		DiamondTrap a;

		a.whoAmI();
		std::cout << a.getAttackDamage() << std::endl;
		a.print_score();
		a.attack("hahahahaha!");
		a.print_score();
	}
	{
		DiamondTrap b("HELLO");

		b.whoAmI();
		std::cout << b.getAttackDamage() << std::endl;
		b.print_score();
		b.attack("hahahahaha!");
		b.print_score();
	}
}

void	virtual_destructor_test(void)
{
	ClapTrap *b = new ScavTrap();
	delete b;

	ClapTrap *c = new FragTrap();
	delete c;

	ClapTrap *d = new DiamondTrap();
	delete d;

	ScavTrap *e = new DiamondTrap();
	delete e;

	FragTrap *f = new DiamondTrap();
	delete f;
}

int main (void)
{
	std::cout << std::endl << "=====ClapTrap tests:=====" << std::endl << std::endl;
	clap_trap_test();
	std::cout << std::endl << "=====ScavTrap tests:=====" << std::endl << std::endl;
	scav_trap_test();
	std::cout << std::endl << "=====FragTrap tests:=====" << std::endl << std::endl;
	frag_trap_test();
	std::cout << std::endl << "=====DiamondTrap tests:=====" << std::endl << std::endl;
	diamond_trap_base_test();
	std::cout << std::endl << std::endl;
	diamond_trap_test();
	virtual_destructor_test();
	return (0);
}
