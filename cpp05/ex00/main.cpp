#include <iostream>
#include "Bureaucrat.hpp"

/**
 * https://www.w3schools.com/CPP/cpp_exceptions.asp
 * 
 * */

void	basic(void)
{
	Bureaucrat b1;
	Bureaucrat b2 = Bureaucrat("Bob", 400);

	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;

	std::cout << std::endl;

	std::cout << b2.getName() << std::endl;
	std::cout << b2.getGrade() << std::endl;
}

int main(void)
{
	//basic();
	//std::string abc = "Hello";
	int abc = 3000;
	try
  	{
  		//std::cout <<"Hello\n";
    	//throw 20;
    	if (abc < 0 || abc > 300)
    		throw abc;
  	}
  	catch (int e)
  	{
    	std::cout << "An exception occurred. Exception Nr. " << e << '\n';
  	}
  	catch (std::string e)
  	{
    	std::cout << "An exception occurred. Exception string. " << e << '\n';
  	}
	return (0);
}