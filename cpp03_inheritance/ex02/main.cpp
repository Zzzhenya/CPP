#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	FragTrap a("Frag_AA");
	FragTrap b("Frag_BB");

	a.print_score();
	b.print_score();
	
	for(int i = 0; i < 110; i++)
	{
		if (!(i%4))
		{
			a.highFivesGuys();
			b.beRepaired(i);
		}
		else if (!(i%3))
		{
			b.attack("Frag_AA");
			a.takeDamage(1);
		}
		else
		{
			a.attack("Frag_BB");
			b.takeDamage(1);
		}
		a.print_score();
		b.print_score();
	}
	return (0);
}