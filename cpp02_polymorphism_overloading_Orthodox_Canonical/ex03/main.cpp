#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <limits.h>

void	pass(void)
{
	std::cout << "\t\t\t\t\t" << "==OK==" << std::endl;
}

void	fail(void)
{
	std::cerr  << "\t\t\t\t\t"<< "=0000=" << std::endl;
}

void	print_triangle(Point a, Point b, Point c)
{
	std::cout << "Test: ";
	std::cout << "(" << a.getX() << "," << a.getY() << "), ";
	std::cout << "(" << b.getX() << "," << b.getY() << "), ";
	std::cout << "(" << c.getX() << "," << c.getY() << ")" << std::endl;
}

void print_point(Point p)
{
	std::cout << "(" << p.getX() << "," << p.getY() << ")" << std::endl;
}

void	negative_case(Point a, Point b, Point c, Point p)
{
	print_point(p);
	if (bsp(a,b,c,p) != 0)
		fail();
	else
	{
	 	pass();
	 	//std::cout << "Point is outside the triangle." << std::endl;
	 }
}

void	positive_case(Point a, Point b, Point c, Point p)
{
	print_point(p);
	if (bsp(a,b,c,p) == 0)
		fail();
	else
	{
		pass();
		std::cout << "Point is inside the triangle." << std::endl;
	}
	//std::cout << std::endl;
}

void	test_90_triangle(void)
{
	Point a(0,0);
	Point b(5,5);
	Point c(5,0);
	std::cout << "==============================="<< std::endl;
	print_triangle(a, b, c);
	std::cout << "==============================="<< std::endl;
	// vertex
	negative_case(a,b,c,Point(0,0));
	// vertex
	negative_case(a,b,c,Point(5,5));
	// vertex
	negative_case(a,b,c,Point(5,0));
	// edge
	negative_case(a,b,c,Point(5,3));
	// outside
	negative_case(a,b,c,Point(-1,3));
	// inside
	positive_case(a,b,c,Point(3,1));
}

void test_from_ref(void)
{
	Point a(22 , 8);
	Point b(12 , 55);
	Point c(7 , 19);

	std::cout << "==============================="<< std::endl;
	print_triangle(a, b, c);
	std::cout << "==============================="<< std::endl;
	//inside 
	positive_case(a,b,c,Point(15,20));
	// outside
	negative_case(a, b, c,Point(1, 7));
	// vertex
	negative_case(a, b, c,Point(7, 19));
}

void	test_not_triangle(void)
{
	Point a(22 , 8);
	Point b(22 , 8);
	Point c(7 , 19);

	std::cout << "==============================="<< std::endl;
	print_triangle(a, b, c);
	std::cout << "==============================="<< std::endl;
	// not inside
	negative_case(a,b,c,Point(15,20));
	// not inside
	negative_case(a, b, c,Point(1, 7));
	// not inside
	negative_case(a, b, c,Point(7, 19));
}

int main(void)
{
	test_90_triangle();
	test_from_ref();
	test_not_triangle();
	return (0);
}