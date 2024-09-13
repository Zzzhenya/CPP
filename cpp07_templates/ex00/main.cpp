/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:27:06 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/13 23:27:36 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include "whatever.hpp"

// template <typename T>void swap(T *x, T *y)
// {
// 	std::cout << "*" << std::endl;
// 	T temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

// void	swap(char *x, char *y)
// {
// 	char temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

class Test
{
	public:
		Test(void): _a(1){};
		Test(int a): _a(a){};
		bool operator>(const Test &other)
		{
			if (this->_a > other._a)
				return (true);
			return (false);
		}
		bool operator<(const Test &other)
		{
			if (this->_a < other._a)
				return (true);
			return (false);
		}
		int _a;
};

std::ostream& operator<<(std::ostream& streamRef,const Test& obj)
{
	streamRef << obj._a;
	return (streamRef);
}

void swap_tests(void)
{
	std::cout << std::endl << "=========== int ============" << std::endl << std::endl;
	{
		int x = 2; int y = 6;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <int> (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;
	}
	std::cout << std::endl << "=========== float ==========" << std::endl << std::endl;
	{
		float x = 2.23f; float y = 6.98f;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <float > (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;	
	}
	std::cout << std::endl << "=========== double ==========" << std::endl << std::endl;
	{
		double x = 2.232; double y = 6.982;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <double> (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;	
	}
	std::cout << std::endl << "=========== char * ==========" << std::endl << std::endl;
	{
		// char x[1] = {'A'}; char y[1] = {'B'};
		// swap <char [1]> (x, y);
		char *x = new char('A'); char *y = new char('B');
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		swap <char *> (x, y);
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		delete x; delete y;
	}
	std::cout << "===========std::string ==========" << std::endl;
	{
		std::string x = std::string("Hello"); 
		std::string y = std::string("World");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - " << y << std::endl;
		swapstr <std::string> (x, y);
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - " << y << std::endl;
	}
	std::cout << "===========std::string *==========" << std::endl;
	{
		std::string *x = new std::string("Hello"); 
		std::string *y = new std::string("World");
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swapstr <std::string *> (x, y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=========== char ============" << std::endl << std::endl;
	{
		char x = 'A'; char y = 'B';
		std::cout << "x: " << (void *)&x << " - "  << x << " | y: " << (void *)&y << " - "  << y << std::endl;
		swap <char > (x, y);
		std::cout << "x: " << (void *)&x << " - "  << x << " | y: " << (void *)&y << " - "   << y << std::endl;
	}
	std::cout << std::endl << "=========== int =============" << std::endl << std::endl;
	{
		int x[1] = {2}; int y[1] = {6};
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <int> (*x, *y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
	}
	std::cout << std::endl << "=========== int * ===========" << std::endl << std::endl;
	{
		//int x[1] = {2}; int y[1] = {6};
		int *x = new int(2); int *y = new int(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <int *> (x, y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=== char *, std::string =====" << std::endl << std::endl;
	{
		std::string str1 = "Hello";
		char *x = new char (str1.length() + 1);
		std::strcpy (x, str1.c_str());
		std::string str2 = "World";
		char *y = new char (str2.length() + 1);
		std::strcpy (y, str2.c_str());
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		swap <char *> (x, y);
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=========== float * ===========" << std::endl << std::endl;
	{
		float *x = new float(4.23f); float *y = new float(2.78f);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <float *> (x, y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=========== size_t * ===========" << std::endl << std::endl;
	{
		size_t *x = new size_t(4); size_t *y = new size_t(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <size_t *> (x, y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=========== Class ============" << std::endl << std::endl;
	{
		Test x = Test(2); Test y = Test(6);
		std::cout << "x: " << &x._a << " - " << x._a << " | y: " << &y._a << " - " << y._a << std::endl;
		swap <Test> (x, y);
		std::cout << "x: " << &x._a << " - " << x._a << " | y: " << &y._a << " - " << y._a << std::endl;
	}
	std::cout << std::endl << "=========== Class * ===========" << std::endl << std::endl;
	{
		Test *x = new Test(); Test *y = new Test();
		std::cout << "x: " << x << " | y: " << y  << std::endl;
		swap <Test *> (x, y);
		std::cout << "x: " << x << " | y: " << y  << std::endl;
		delete x; delete y;
	}
}

void max_tests(void)
{
	std::cout << std::endl << "=========== int ============" << std::endl << std::endl;
	{
		int x = 2; int y = 6;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <int> (x, y) << " - " << max <int> (x, y) << std::endl;
		x = 2; y = 2;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <int> (x, y) << " - " << max <int> (x, y) << std::endl;
		x = 6; y = 2;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <int> (x, y) << " - " << max <int> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== int * ============" << std::endl << std::endl;
	{
		int *x = new int(2); 
		int *y = new int(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <int *> (x, y) << " - " << *max <int *> (x, y) << std::endl;
		delete x; delete y;
		x = new int(2); y = new int(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <int *> (x, y) << " - " << *max <int *> (x, y) << std::endl;
		delete x; delete y;
		x = new int(6); y = new int(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <int *> (x, y) << " - " << *max <int *> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== Class ============" << std::endl << std::endl;
	{
		Test *x = new Test(2); 
		Test *y = new Test(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << &(max <Test> (*x, *y)) << " - " << max <Test> (*x, *y) << std::endl;
		delete x; delete y;
		x = new Test(2); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << &(max <Test> (*x, *y)) << " - " << max <Test> (*x, *y) << std::endl;
		delete x; delete y;
		x = new Test(6); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << &(max <Test> (*x, *y)) << " - " << max <Test> (*x, *y) << std::endl;
	}
	std::cout << std::endl << "=========== Class * ============" << std::endl << std::endl;
	{
		Test *x = new Test(2); 
		Test *y = new Test(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <Test *> (x, y) << " - " << *max <Test *> (x, y) << std::endl;
		delete x; delete y;
		x = new Test(2); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <Test *> (x, y) << " - " << *max <Test *> (x, y) << std::endl;
		delete x; delete y;
		x = new Test(6); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "max :" << max <Test *> (x, y) << " - " << *max <Test *> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== std::string ============" << std::endl << std::endl;
	{
		std::string x = std::string("Hello");
		std::string y = std::string("World");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <std::string> (x, y) << " - " << max <std::string> (x, y) << std::endl;
		y = std::string("Hello");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <std::string> (x, y) << " - " << max <std::string> (x, y) << std::endl;
		x = std::string("World");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "max :" << &max <std::string> (x, y) << " - " << max <std::string> (x, y) << std::endl;
	}
}

void min_tests(void)
{
	std::cout << std::endl << "=========== int ============" << std::endl << std::endl;
	{
		int x = 2; int y = 6;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <int> (x, y) << " - " << min <int> (x, y) << std::endl;
		x = 2; y = 2;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <int> (x, y) << " - " << min <int> (x, y) << std::endl;
		x = 6; y = 2;
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <int> (x, y) << " - " << min <int> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== int * ============" << std::endl << std::endl;
	{
		int *x = new int(2); 
		int *y = new int(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <int *> (x, y) << " - " << *min <int *> (x, y) << std::endl;
		delete x; delete y;
		x = new int(2); y = new int(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <int *> (x, y) << " - " << *min <int *> (x, y) << std::endl;
		delete x; delete y;
		x = new int(6); y = new int(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <int *> (x, y) << " - " << *min <int *> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== Class ============" << std::endl << std::endl;
	{
		Test *x = new Test(2); 
		Test *y = new Test(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << &(min <Test> (*x, *y)) << " - " << min <Test> (*x, *y) << std::endl;
		delete x; delete y;
		x = new Test(2); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << &(min <Test> (*x, *y)) << " - " << min <Test> (*x, *y) << std::endl;
		delete x; delete y;
		x = new Test(6); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << &(min <Test> (*x, *y)) << " - " << min <Test> (*x, *y) << std::endl;
	}
	std::cout << std::endl << "=========== Class * ============" << std::endl << std::endl;
	{
		Test *x = new Test(2); 
		Test *y = new Test(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <Test *> (x, y) << " - " << *min <Test *> (x, y) << std::endl;
		delete x; delete y;
		x = new Test(2); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <Test *> (x, y) << " - " << *min <Test *> (x, y) << std::endl;
		delete x; delete y;
		x = new Test(6); y = new Test(2);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - "<< *y << std::endl;
		std::cout << "min :" << min <Test *> (x, y) << " - " << *min <Test *> (x, y) << std::endl;
	}
	std::cout << std::endl << "=========== std::string ============" << std::endl << std::endl;
	{
		std::string x = std::string("Hello");
		std::string y = std::string("World");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <std::string> (x, y) << " - " << min <std::string> (x, y) << std::endl;
		y = std::string("Hello");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <std::string> (x, y) << " - " << min <std::string> (x, y) << std::endl;
		x = std::string("World");
		std::cout << "x: " << &x << " - " << x << " | y: " << &y << " - "<< y << std::endl;
		std::cout << "min :" << &min <std::string> (x, y) << " - " << min <std::string> (x, y) << std::endl;
	}
}

int main(void)
{
	std::cout << std::endl << "============================\tswap\t====" << std::endl;
	swap_tests();
	std::cout << std::endl << "============================\tmax\t====" << std::endl;
	max_tests();
	std::cout << std::endl << "============================\tmin\t====" << std::endl;
	min_tests();
	std::cout << std::endl;
	return (0);
}
