#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
		Point(const float x, const float y);
		// Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point& 	operator=(const Point &other);

		Fixed *getPoint(Fixed ret[2]) const;
		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const x;
		Fixed const y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif