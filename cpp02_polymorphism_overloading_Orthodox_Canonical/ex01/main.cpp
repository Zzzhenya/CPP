#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(1);
	// float neads a f at the end?
	Fixed b(2); // 1.1d
	//Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}