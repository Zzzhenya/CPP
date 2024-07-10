#include "Fixed.hpp"
#include <iostream>
#include <limits>

void	print_int_vals(int first, int second, char c)
{
	Fixed a(first);
	Fixed b(second);

	std::cout << "a: " << a << "\tb: " << b << "\t\t";
	if (c == '>')
	{
		if (a > b)
			std::cout << a << " > " << b << std::endl;
		else if (b > a)
			std::cout << b << " > " << a << std::endl;
		else
			std::cout << a << " = " << b << std::endl;
	}
	else if (c == '<')
	{
		if (a < b)
			std::cout << a << " < " << b << std::endl;
		else if (b < a)
			std::cout << b << " < " << a << std::endl;
		else
			std::cout << a << " = " << b << std::endl;
	}
}

void	print_float_vals(float first, float second, char c)
{
	Fixed a(first);
	Fixed b(second);
	
	std::cout << "a: " << a << "\tb: " << b << "\t\t";
	if (c == '>')
	{
		if (a > b)
			std::cout << a << " > " << b << std::endl;
		else if (b > a)
			std::cout << b << " > " << a << std::endl;
		else
			std::cout << a << " = " << b << std::endl;
	}
}
void	int_tests(char op)
{
	print_int_vals(1, 2, op);
	print_int_vals(2, 1, op);
	print_int_vals(1, 1, op);
	print_int_vals(0, 0, op);
	print_int_vals(0, -1, op);
	print_int_vals(-2, -1, op);
	print_int_vals(2000, 3000, op);
}


int main(void)
{
	int_tests('>');
	int_tests('<');

	// a = Fixed(0);


	return (0);
}