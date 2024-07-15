#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		FragTrap(std::string name);

		void	highFivesGuys(void);
		void	attack(const std::string& target);

};

#endif