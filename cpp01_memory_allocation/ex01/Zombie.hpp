#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif