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
			a.takeDamage(1);// b.getDamageCount()
		}
		a.print_score();
		b.print_score();
	}
	return (0);
}