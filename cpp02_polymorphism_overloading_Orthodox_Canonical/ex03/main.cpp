#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <limits.h>

// void	print_int_vals(int first, int second, std::string op)
// {
// 	Fixed a(first);
// 	Fixed b(second);
// 	int ok = 0;
	
// 	if (op == ">" )
// 	{
// 		if ((a > b) && (first > second))
// 			ok = 1;
// 		else if ((b > a) && (second > first))
// 			ok = 1;
// 		else
// 			if (first == second)
// 				ok = 1;
// 	}
// 	else if (op == "<")
// 	{
// 		if ((a < b) && (first < second))
// 			ok = 1;
// 		else if ((b < a) && (second < first))
// 			ok = 1;
// 		else
// 			if (first == second)
// 				ok = 1;
// 	}
// 	else if (op == ">=")
// 	{
// 		if ((a >= b) && (first >= second))
// 			ok = 1;
// 		else if ((b >= a) && (second >= first))
// 			ok = 1;
// 	}
// 	else if (op == "<=")
// 	{
// 		if ((a <= b) && (first <= second))
// 			ok = 1;
// 		else if ((b <= a) && (second <= first))
// 			ok = 1;
// 	}
// 	else if (op == "==")
// 	{
// 		if ((a == b) && (first == second))
// 			ok = 1;
// 		else if ((a != b) && (first != second))
// 			ok = 1;
// 	}
// 	else if (op == "!=")
// 	{
// 		if ((a != b) && (first != second))
// 			ok = 1;
// 		else if ((a != b) && (first != second))
// 			ok = 1;
// 	}
// 	else if ((op == "+") && ((a + b) == (first + second)))
// 		ok = 1;
// 	else if ((op == "-") && ((a - b) == (first - second)))
// 		ok = 1;
// 	else if ((op == "*") && ((a * b) == (first * second)))
// 		ok = 1;
// 	else if ((op == "/") && ((a / b) == (first / second)))
// 		ok = 1;
// 	switch(ok)
// 	{
// 		case 1:
// 			std::cout << "--OK--";
// 			std::cout << "\t\t " << first << "\t" << second << std::endl;
// 			break;
// 		case 0:
// 			std::cout << "000000";
// 			std::cout << "\t\t " << first << "\t" << second << "\t\ta: " << a << " b: " << b << std::endl;
// 			break;
// 	}
// }

// void	print_float_vals(float first, float second, std::string op)
// {
// 	Fixed a(first);
// 	Fixed b(second);
// 	int ok = 0;
	
// 	if (op == ">" )
// 	{
// 		if ((a > b) && (first > second))
// 			ok = 1;
// 		else if ((b > a) && (second > first))
// 			ok = 1;
// 		else
// 			if (first == second)
// 				ok = 1;
// 	}
// 	else if (op == "<")
// 	{
// 		if ((a < b) && (first < second))
// 			ok = 1;
// 		else if ((b < a) && (second < first))
// 			ok = 1;
// 		else
// 			if (first == second)
// 				ok = 1;
// 	}
// 	else if (op == ">=")
// 	{
// 		if ((a >= b) && (first >= second))
// 			ok = 1;
// 		else if ((b >= a) && (second >= first))
// 			ok = 1;
// 	}
// 	else if (op == "<=")
// 	{
// 		if ((a <= b) && (first <= second))
// 			ok = 1;
// 		else if ((b <= a) && (second <= first))
// 			ok = 1;
// 	}
// 	else if (op == "==")
// 	{
// 		if ((a == b) && (first == second))
// 			ok = 1;
// 		else if ((a != b) && (first != second))
// 			ok = 1;
// 	}
// 	else if (op == "!=")
// 	{
// 		if ((a != b) && (first != second))
// 			ok = 1;
// 		else if((a == b) && (first == second))
// 			ok = 1;
// 	}
// 	else if ((op == "+") && ((a + b) == (first + second)))
// 		ok = 1;
// 	else if ((op == "-") && ((a - b) == (first - second)))
// 		ok = 1;
// 	else if ((op == "*") && ((a * b) == (first * second)))
// 		ok = 1;
// 	else if ((op == "/") && ((a / b) == (first / second)))
// 		ok = 1;
// 	switch(ok)
// 	{
// 		case 1:
// 			std::cout << "--OK--";
// 			std::cout << "\t\t " << first << "\t" << second << std::endl;
// 			break;
// 		case 0:
// 			std::cout << "000000";
// 			std::cout << "\t\t " << first << "\t" << second << "\t\ta: " << a << " b: " << b << std::endl;
// 			break;
// 	}
// }

// void	int_tests(std::string op)
// {
// 	print_int_vals(1, 2, op);
// 	print_int_vals(2, 1, op);
// 	print_int_vals(1, 1, op);
// 	if (op != "/")
// 		print_int_vals(0, 0, op);
// 	print_int_vals(0, -1, op);
// 	print_int_vals(-2, -1, op);
// 	print_int_vals(2000, 3000, op);
// 	print_int_vals(2000000, 3000000, op);
// 	print_int_vals(200000000, 300000000, op);
// }

// void	float_tests(std::string op)
// {

// 	print_float_vals(1.1, 2.0, op);
// 	print_float_vals(2.0, 1.1, op);
// 	print_float_vals(1.10, 1.101, op);
// 	if (op != "/")
// 		print_float_vals(0, 0, op);
// 	print_float_vals(0, -1.12, op);
// 	print_float_vals(-2.2, -1.12, op);
// 	print_float_vals(-2.2, -2.19922, op);
// 	print_float_vals(1/2000, 1/3000, op);
// }


int main(void)
{
	Point t1(10, 20);
	Point t2(4, 8);
	Point t3(20, 10);
	Point p(10, 8.5f);

	std::cout << "\t";
	if (is_inside_triangle(t1, t2, t3, p) && area_calc(t1, t2, t3, p))
		std::cout << "is inside." << std::endl;
	else if (is_inside_triangle(t1, t2, t3, p) || area_calc(t1, t2, t3, p))
		std::cout << "Error." << std::endl;
	else
		std::cout << " is outside." << std::endl;
	return (0);
}