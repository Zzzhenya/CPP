#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	std::cout << "Default Point constructor called." << std::endl;
	// this->x = 0;
	// this->y = 0;
}

Point::~Point(void)
{
	std::cout << "Point destructor called." << std::endl;
}

// Point::Point(const Fixed x, const Fixed y)
// {
// 	std::cout << "Point constructor called with x,y fixed coordinates." << std::endl;
// 	this->x = x;
// 	this->y = y;
// }

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b))
{
	std::cout << "Point constructor called with x,y float coordinates." << std::endl;
	// this->x = Fixed(x);
	// this->y = Fixed(y);
}

Point::Point(const Point &p) : x(p.x), y(p.y)
{
	std::cout << "Point copy constructor called." << std::endl;
	// this->x = p.x;
	// this->y = p.y;
}

Point& 	Point::operator=(const Point &other)
{
	std::cout << "Unable to call Point copy assignment operator.\n";
	(void)other;
	// Fixed temp[2];
	// other.getPoint(temp);
	// this->x = temp[0];
	// this->y = temp[1];
	// this->x = other.getX();
	// this->y = other.getY();
	return (*this);
}

Fixed* Point::getPoint(Fixed ret[2]) const
{
	ret[0] = this->x;
	ret[1] = this->y;
	return(ret);
}

Fixed Point::getX(void) const
{
	Fixed x = this->x;
	return (x);
}

Fixed Point::getY(void) const
{
	Fixed y = this->y;
	return (y);
}
