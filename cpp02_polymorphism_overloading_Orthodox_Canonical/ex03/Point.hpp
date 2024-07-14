#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &p);
		Point& 	operator=(const Point &other);

		Fixed *getPoint(Fixed ret[2]) const;
		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed x;
		Fixed y;
};

bool	is_inside_triangle(const Point& t1, const Point& t2, const Point& t3, const Point& p);
bool 	area_calc(const Point& t1, const Point& t2, const Point& t3, const Point& p);

#endif