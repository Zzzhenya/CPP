/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:53:20 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 22:05:05 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int less_than_int(float first, float second, Fixed &a, Fixed &b)
{
	if ((a < b) && (first < second))
		return (1);
	else if ((b < a) && (second < first))
		return (1);
	else
	{
		if (first == second)
			return (1);
	}
	return (0);	
}

int less_than_float(float first, float second, Fixed &a, Fixed &b)
{
	if ((a < b) && (first < second))
		return (1);
	else if ((b < a) && (second < first))
		return (1);
	else
	{
		if (first == second)
			return (1);
	}
	return (0);	
}

int greater_than_int(int first, int second, Fixed &a, Fixed &b)
{
	if ((a > b) && (first > second))
		return (1);
	else if ((b > a) && (second > first))
		return (1);
	else
	{
		if (first == second)
			return (1);
	}
	return (0);
}

int greater_than_float(float first, float second, Fixed &a, Fixed &b)
{
	if ((a > b) && (first > second))
		return (1);
	else if ((b > a) && (second > first))
		return (1);
	else
	{
		if (first == second)
			return (1);
	}
	return (0);
}

int equals_int(int first, int second, Fixed &a, Fixed &b, std::string &op)
{
	if (op == ">=")
	{
		if ((a >= b) && (first >= second))
			return (1);
		else if ((b >= a) && (second >= first))
			return (1);
	}
	else if (op == "<=")
	{
		if ((a <= b) && (first <= second))
			return (1);
		else if ((b <= a) && (second <= first))
			return (1);
	}
	else if (op == "==")
	{
		if ((a == b) && (first == second))
			return (1);
		else if ((a != b) && (first != second))
			return (1);
	}
	else if (op == "!=")
	{
		if ((a != b) && (first != second))
			return (1);
		else if((a == b) && (first == second))
			return (1);
	}
	return (0);
}


int equals_float(float first, float second, Fixed &a, Fixed &b, std::string &op)
{
	if (op == ">=")
	{
		if ((a >= b) && (first >= second))
			return (1);
		else if ((b >= a) && (second >= first))
			return (1);
	}
	else if (op == "<=")
	{
		if ((a <= b) && (first <= second))
			return (1);
		else if ((b <= a) && (second <= first))
			return (1);
	}
	else if (op == "==")
	{
		if ((a == b) && (first == second))
			return (1);
		else if ((a != b) && (first != second))
			return (1);
	}
	else if (op == "!=")
	{
		if ((a != b) && (first != second))
			return (1);
		else if((a == b) && (first == second))
			return (1);
	}
	return (0);
}

void	print_int_vals(int first, int second, std::string op)
{
	Fixed a(first);
	Fixed b(second);
	int ok = 0;
	
	if (op == ">" )
		ok = greater_than_int(first, second, a, b);
	else if (op == "<")
		ok = less_than_int(first, second, a, b);
	else if (op == ">=" || op == "<=" || op == "==" || op == "!=")
		ok = equals_int(first, second, a, b, op);
	else if ((op == "+") && ((a + b) == (first + second)))
		ok = 1;
	else if ((op == "-") && ((a - b) == (first - second)))
		ok = 1;
	else if ((op == "*") && ((a * b) == (first * second)))
		ok = 1;
	else if ((op == "/") && ((a / b) == (first / second)))
		ok = 1;
	switch(ok)
	{
		case 1:
			std::cout << "--OK--";
			std::cout << "\t\t " << first << "\t" << second << std::endl;
			break;
		case 0:
			std::cout << "000000";
			std::cout << "\t\t " << first << "\t" << second << "\t\ta: " << a << " b: " << b << std::endl;
			break;
	}
}

void	print_float_vals(float first, float second, std::string op)
{
	Fixed a(first);
	Fixed b(second);
	int ok = 0;
	
	if (op == ">" )
		ok = greater_than_float(first, second, a, b);
	else if (op == "<")
		ok = less_than_float(first, second, a, b);
	else if (op == ">=" || op == "<=" || op == "==" || op == "!=")
		ok = equals_float(first, second, a, b, op);
	else if ((op == "+") && ((a + b) == (first + second)))
		ok = 1;
	else if ((op == "-") && ((a - b) == (first - second)))
		ok = 1;
	else if ((op == "*") && ((a * b) == (first * second)))
		ok = 1;
	else if ((op == "/") && ((a / b) == (first / second)))
		ok = 1;
	switch(ok)
	{
		case 1:
			std::cout << "--OK--";
			std::cout << "\t\t " << first << "\t" << second << std::endl;
			break;
		case 0:
			std::cout << "000000";
			std::cout << "\t\t " << first << "\t" << second;
			std::cout << "\t\ta: " << a << " b: " << b << std::endl;
			break;
	}
}

void	int_tests(std::string op)
{
	print_int_vals(1, 2, op);
	print_int_vals(2, 1, op);
	print_int_vals(1, 1, op);
	if (op != "/")
		print_int_vals(0, 0, op);
	print_int_vals(0, -1, op);
	print_int_vals(-2, -1, op);
	print_int_vals(200, 300, op);
	print_int_vals(2000, 3000, op);
	print_int_vals(2000000, 3000000, op);
	print_int_vals(200000000, 300000000, op);
}

void	float_tests(std::string op)
{

	print_float_vals(1.1, 2.0, op);
	print_float_vals(2.0, 1.1, op);
	print_float_vals(1.10, 1.101, op);
	if (op != "/")
		print_float_vals(0, 0, op);
	print_float_vals(0, -1.12, op);
	print_float_vals(-2.2, -1.12, op);
	print_float_vals(-2.2, -2.19922, op);
	if (op != "/")
		print_float_vals(1/2000, 1/3000, op);
}

void int_comparison(void)
{
	std::cout << "\t==========COMPARISON OPERATORS============\n";
	std::cout << "\t_______ > _________" << std::endl;
	int_tests(">");
	std::cout << "\t_______ < _________" << std::endl;
	int_tests("<");
	std::cout << "\t_______ >= _________" << std::endl;
	int_tests(">=");
	std::cout << "\t_______ <= _________" << std::endl;
	int_tests("<=");
	std::cout << "\t_______ == _________" << std::endl;
	int_tests("==");
	std::cout << "\t_______ != _________" << std::endl;
	int_tests("!=");
}

void float_comparison(void)
{
	std::cout << "\t==========COMPARISON OPERATORS============\n";
	std::cout << "\t_______ > _________" << std::endl;
	float_tests(">");
	std::cout << "\t_______ < _________" << std::endl;
	float_tests("<");
	std::cout << "\t_______ >= _________" << std::endl;
	float_tests(">=");
	std::cout << "\t_______ <= _________" << std::endl;
	float_tests("<=");
	std::cout << "\t_______ == _________" << std::endl;
	float_tests("==");
	std::cout << "\t_______ != _________" << std::endl;
	float_tests("!=");
}

void int_arithmetic(void)
{
	std::cout << "\n\t==========ARITHMETIC OPERATORS============\n";
	std::cout << "\t_______ + _________" << std::endl;
	int_tests("+");
	std::cout << "\t_______ - _________" << std::endl;
	int_tests("-");
	std::cout << "\t_______ * _________" << std::endl;
	int_tests("*");
	std::cout << "\t_______ / _________" << std::endl;
	int_tests("/");
}

void float_arithmetic(void)
{
	std::cout << "\n\t==========ARITHMETIC OPERATORS============\n";
	std::cout << "\t_______ + _________" << std::endl;
	float_tests("+");
	std::cout << "\t_______ - _________" << std::endl;
	float_tests("-");
	std::cout << "\t_______ * _________" << std::endl;
	float_tests("*");
	std::cout << "\t_______ / _________" << std::endl;
	float_tests("/");
}

void extended_subject_tests(void)
{
	Fixed a(-1.1f);
	Fixed b(-11);

	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	a = 10;

	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;

	a = 10;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
}

void	subject_tests(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main(void)
{
	subject_tests();
	extended_subject_tests();
	int_comparison();
	float_comparison();
	int_arithmetic();
	float_arithmetic();
	return (0);
}