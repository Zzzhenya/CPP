#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define GET_VARIABLE_NAME(Variable) (#Variable)

int main(void)
{
	// Weapon *w1 = new Weapon("type1");

	// std::cout << GET_VARIABLE_NAME(w1) << " type: " << w1->getType() << std::endl;
	// w1->setType("Jaja");
	// std::cout << GET_VARIABLE_NAME(w1) << " type: " << w1->getType() << std::endl;
	// delete w1;

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}