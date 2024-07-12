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
	Point a(1, 2);
	Fixed *ret = new Fixed[2];


	ret = a.getPoint(ret);
	std::cout << ret[0] << ", " << ret[1] << std::endl;

	delete []ret;
	return (0);
}