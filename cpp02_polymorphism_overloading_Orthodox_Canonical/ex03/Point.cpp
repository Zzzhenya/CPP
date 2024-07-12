#include "Point.hpp"

Point::Point(void)
{
	std::cout << "Default Point constructor called." << std::endl;
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

Fixed *Point::getPoint(Fixed ret[2])
{
	//Fixed *ret = new Fixed[2];

	ret[0] = this->x;
	ret[1] = this->y;

	return(ret);
}