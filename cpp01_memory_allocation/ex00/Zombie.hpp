#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void	announce(void); // get_name();
	private:
		std::string name;
	
};

/*
	It creates a zombie, name it, 
	and return it so you can use it outside 
	of the function scope.
*/

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif