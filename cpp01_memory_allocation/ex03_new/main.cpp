#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(void)
{
	// Weapon tests

	Weapon one("Random");
	Weapon two("");

	std::cout << one.getType() << std::endl;
	std::cout << two.getType()<< std::endl;
	two.setType("Clubby club");
	std::cout << two.getType() << std::endl;


	// basic tests - HumanA
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	// basic tests - HumanB
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	// Human A Null/Empty tests
	// {
	// 	Weapon club = Weapon("");
	// 	Weapon club = Weapon(NULL);
	// 	std::cout << club.getType() << std::endl;
	// 	HumanA bob("Bob", club);
	// 	bob.attack();
	// 	club.setType("some other type of club");
	// 	bob.attack();
	// }
	return(0);
}