#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap a("Scav_AA");
	ScavTrap b("Scav_BB");

	a.print_score();
	b.print_score();
	
	for(int i = 0; i < 110; i++)
	{
		if (!(i%4))
		{
			a.guardGate();
			b.beRepaired(i);
		}
		else if (!(i%3))
		{
			b.attack("Scav_AA");
			a.takeDamage(1);
		}
		else
		{
			a.attack("Scav_BB");
			b.takeDamage(1);
		}
		a.print_score();
		b.print_score();
	}
	return (0);
}