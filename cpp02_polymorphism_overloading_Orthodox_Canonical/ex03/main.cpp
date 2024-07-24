#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <limits.h>

int main(void)
{
	Point t1(0, 0);
	Point t2(1, 1);
	Point t3(2, 2);
	Point p(0.3f, 0.3f);
	// Point t1(10, 20);
	// Point t2(4, 8);
	// Point t3(20, 10);
	// Point p(10, 8.5f);

	if (is_inside_triangle(t1, t2, t3, p))
		std::cout << "\t\tIS inside the triangle\n";
	else
		std::cout << "\t\tfalse\n";
	if  (area_calc(t1, t2, t3, p))
		std::cout << "\t\tarea calc TRUE\n";
	else
		std::cout << "\t\tFALSE\n";
	// if (is_inside_triangle(t1, t2, t3, p) && area_calc(t1, t2, t3, p))
	// 	std::cout << "\tThe point is inside." << std::endl;
	// else if (is_inside_triangle(t1, t2, t3, p) || area_calc(t1, t2, t3, p))
	// 	std::cout << "\tError." << std::endl;
	// else
	// 	std::cout << "\tThe point is outside." << std::endl;
	return (0);
}