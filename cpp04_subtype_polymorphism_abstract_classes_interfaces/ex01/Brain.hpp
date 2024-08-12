#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define IDEA_LIMIT 100

class Brain
{
	public:
		Brain(void);
		~Brain(void);

	private:
		std::string ideas[IDEA_LIMIT];
};

#endif