#include "AMateria.hpp"
#include <iostream>

void amateria_tests_before_abstraction(void)
{
	AMateria abc("one");

	std::cout << "Type: " << abc.getType() << std::endl;	
}

int main (void)
{
	amateria_tests_before_abstraction();

	return (0);
}