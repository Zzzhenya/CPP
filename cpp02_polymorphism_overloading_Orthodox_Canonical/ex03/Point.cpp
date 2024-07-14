#include "Point.hpp"

Point::Point(void)
{
	std::cout << "Default Point constructor called." << std::endl;
	this->x = 0;
	this->y = 0;
}

Point::~Point(void)
{
	std::cout << "Point destructor called." << std::endl;
}

Point::Point(const Fixed x, const Fixed y)
{
	std::cout << "Point constructor called with x,y coordinates." << std::endl;
	this->x = x;
	this->y = y;
}

Point::Point(const Point &p)
{
	std::cout << "Point copy constructor called." << std::endl;
	this->x = p.x;
	this->y = p.y;
}

Point& 	Point::operator=(const Point &other)
{
	std::cout << "Poing copy assignment operator called.\n";
	Fixed temp[2];
	other.getPoint(temp);
	x = temp[0];
	y = temp[1];
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
