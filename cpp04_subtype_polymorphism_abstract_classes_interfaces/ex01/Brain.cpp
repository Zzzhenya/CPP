#include "Brain.hpp"

Brain::Brain(void)
{
	int i = 0;

	while (i < IDEA_LIMIT)
	{
		this->ideas[i] = "Something";
		i ++;
	}
	std::cout << "Brain default constructor called.";
	std::cout << std::endl;
}

Brain::~Brain(void)
{
	int i = 0;

	while (i < IDEA_LIMIT)
	{
		this->ideas[i] = "";
		i ++;
	}
	std::cout << "Brain destructor called.";
	std::cout << std::endl;
}