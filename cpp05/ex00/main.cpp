#include <iostream>
#include "Bureaucrat.hpp"

void	basic_stack(std::string name, int val)
{
	Bureaucrat b2 = Bureaucrat(name, val);
	std::cout << b2.getName() << " " << b2.getGrade() << std::endl;
}

void	basic_heap(std::string name, int val)
{
	Bureaucrat *b1 = new Bureaucrat(name, val);
	std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
	delete b1;
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
		basic_stack("Bob", 20);
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
			std::cerr << "ERROR" << std::endl;
		}
	}
	std::cout << "Stack\n";
	{
		try
		{
			basic_stack("Bob", 0);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
	{
		try
		{
			basic_stack("Bob", 400);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_LOW)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
	{
		try
		{
			basic_stack("Bob", -10);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
	std::cout << "Heap\n";
	{
		try
		{
			basic_heap("Bob", 0);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
	{
		try
		{
			basic_heap("Bob", 400);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_LOW)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
	{
		try
		{
			basic_heap("Bob", -10);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
	}
}

int main(void)
{
	simple_tests();
	return (0);
}