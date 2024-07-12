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

		Fixed *getPoint(Fixed ret[2]);

	private:
		Fixed x;
		Fixed y;
};

#endif