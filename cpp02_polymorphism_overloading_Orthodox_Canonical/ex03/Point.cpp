#include "Point.hpp"

/*
	Default constructor
*/
Point::Point(void) : x(0), y(0)
{
	std::cout << "Default Point constructor called." << std::endl;
}

/*
	Destructor
*/
Point::~Point(void)
{
	std::cout << "Point destructor called." << std::endl;
}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b))
{
	std::cout << "Point constructor called with x,y float coordinates." << std::endl;
}

/*
	Copy constructor
*/
Point::Point(const Point &other) : x(other.x), y(other.y)
{
	std::cout << "Point copy constructor called." << std::endl;
}


/*
	Copy assignment operator overload
*/
Point& 	Point::operator=(const Point &other)
{
	std::cout << "Unable to call Point copy assignment operator.";
	std::cout << "Point class has const private variables." << std::endl;
	(void)other;
	return (*this);
}

/* 
	Getter for Point coordinate pair
	receives Fixed[2] array pointer manipulates and returns it;
*/
Fixed* Point::getPoint(Fixed ret[2]) const
{
	if (ret)
	{
		ret[0] = this->getX();
		ret[1] = this->getY();
	}
	return (ret);
}

/*
	getter for x
*/
Fixed Point::getX(void) const
{
	return (this->x);
}
/*
	getter for y
*/
Fixed Point::getY(void) const
{
	return (this->y);
}
