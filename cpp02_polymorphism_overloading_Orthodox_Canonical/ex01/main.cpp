#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(1.01f);
	// float neads a f at the end?
	Fixed b(2.01f); // 1.1d
	//Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;


	std::cout << "_________________________________\n";

	std::cout << a.toInt() << std::endl;
	std::cout << b.toInt() << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << a.toFloat() << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << c.toFloat() << std::endl;

	return (0);
}