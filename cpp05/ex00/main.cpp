#include <iostream>
#include "Bureaucrat.hpp"

void	too_low(void)
{
	Bureaucrat b2 = Bureaucrat("Bob", 400);
	std::cout << b2.getName() << " " << b2.getGrade() << std::endl;
}

void	too_high(void)
{
	Bureaucrat b2 = Bureaucrat("Bob", 0);
	std::cout << b2.getName() << " " << b2.getGrade() << std::endl;
}

void	negative(void)
{
	Bureaucrat b2 = Bureaucrat("Bob", -20);
	std::cout << b2.getName() << " " << b2.getGrade() << std::endl;
}

void basic(void)
{
	std::cout << "Basic tests." << std::endl;
	{
		Bureaucrat b1;
		std::cout << b1.getName() << " " << b1.getGrade() << std::endl;
		debug(std::cerr << "=======================================\n");
	}
	{
		Bureaucrat b1 = Bureaucrat("Bob", 20);
		std::cout << b1.getName() << " " << b1.getGrade() << std::endl;
		debug(std::cerr << "=======================================\n");
	}
	{
		Bureaucrat *b1 = new Bureaucrat();
		std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
		delete b1;
		debug(std::cerr << "=======================================\n");
	}
	{
		Bureaucrat *b1 = new Bureaucrat("Bob", 4);
		std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
		delete b1;
		debug(std::cerr << "=======================================\n");
	}
}

void	simple_tests(void)
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
			too_low();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
			if (std::string(e.what()) == E_TOO_LOW)
				std::cout << "\t\t\t\t\tPASS" << std::endl;
		}
	}
	{
		try
		{
			too_high();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cout << "\t\t\t\t\tPASS" << std::endl;
		}
	}
	{
		try
		{
			negative();
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
			if (std::string(e.what()) == E_TOO_LOW)
				std::cout << "\t\t\t\t\tPASS" << std::endl;
		}
	}
}

int main(void)
{
	simple_tests();
	return (0);
}