#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &arm);
		~HumanA(void);

		void	attack(void);

	private:
		Weapon&			arm;
		std::string		name;
};

#endif