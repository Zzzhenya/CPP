#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		//HumanA();
		HumanA(std::string name, Weapon &arm);

		void	attack(void);

	private:
		std::string name;
		Weapon		&arm;
};

#endif