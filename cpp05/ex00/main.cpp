#include <iostream>
#include "Bureaucrat.hpp"

void	basic_stack(std::string name, int val)
{
	Bureaucrat b2 = Bureaucrat(name, val);
	std::cout << b2;
	debug(std::cerr << "=======================================\n");
}

void	basic_heap(std::string name, int val)
{
	Bureaucrat *b1 = new Bureaucrat(name, val);
	std::cout << *b1;
	delete b1;
	debug(std::cerr << "=======================================\n");
}

void basic(void)
{
	std::cout << "Basic tests." << std::endl;
	{
		Bureaucrat b1;
		std::cout << b1;
		debug(std::cerr << "=======================================\n");
	}
	{
		basic_stack("Bob", 20);
	}
	{
		Bureaucrat *b1 = new Bureaucrat();
		std::cout << *b1;
		delete b1;
		debug(std::cerr << "=======================================\n");
	}
	{
		basic_heap("Bob", 4);
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

void	combination_test(void)
{
	{
		try
		{
			Bureaucrat b1 = Bureaucrat("Bob", 1);
			for (int i = 0; i < 500; i++)
			{
				if (b1.getGrade() % 10 == 0)
					std::cout << b1;
				b1.downGrade();
			}
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_LOW)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
		debug(std::cerr << "=======================================\n");
	}
	{
		try
		{
			Bureaucrat b1 = Bureaucrat("Bob", 150);
			for (int i = 0; i < 500; i++)
			{
				if (b1.getGrade() % 10 == 0 || b1.getGrade() < 10)
					std::cout << b1;
				b1.upGrade();
			}
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == E_TOO_HIGH)
				std::cerr << e.what() << std::endl;
			else
				std::cerr << "ERROR" << std::endl;
		}
		debug(std::cerr << "=======================================\n");
	}
}

int main(void)
{
	bool i = 1;
	simple_tests();
	combination_test();
	assert(i);
	return (0);
}