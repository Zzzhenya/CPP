#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		~DiamondTrap(void);

	// private:
	// 	std::string name;
};

#endif