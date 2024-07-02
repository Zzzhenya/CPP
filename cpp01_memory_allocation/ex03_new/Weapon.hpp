#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);

		const std::string& getType(void);
		void setType(std::string newtype);

	private:
		std::string	type;
};

#endif
