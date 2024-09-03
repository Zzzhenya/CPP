#include <iostream>
#include "Bureaucrat.hpp"


void	basic(void)
{
	Bureaucrat b1;

	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;

	std::cout << std::endl;

	Bureaucrat b2 = Bureaucrat("Bob", 400);

	std::cout << b2.getName() << std::endl;
	std::cout << b2.getGrade() << std::endl;
}

int main(void)
{
	{
		try
		{
			basic();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try
		{
			basic();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}