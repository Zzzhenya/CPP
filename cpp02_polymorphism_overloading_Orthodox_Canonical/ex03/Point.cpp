#include "Point.hpp"

/*
	Default constructor
*/
Point::Point(void) : x(0), y(0)
{
#ifdef _DEBUG
#else
	std::cout << "Default Point constructor called." << std::endl;
#endif
}

/*
	Destructor
*/
Point::~Point(void)
{
#ifdef _DEBUG
#else
	std::cout << "Point destructor called." << std::endl;
#endif
}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b))
{
#ifdef _DEBUG
#else
	std::cout << "Point constructor called with x,y float coordinates." << std::endl;
#endif
}

/*
	Copy constructor
*/
Point::Point(const Point &other) : x(other.x), y(other.y)
{
#ifdef _DEBUG
#else
	std::cout << "Point copy constructor called." << std::endl;
#endif
}


/*
	Copy assignment operator overload
*/
Point& 	Point::operator=(const Point &other)
{
#ifdef _DEBUG
#else
	std::cout << "Unable to call Point copy assignment operator.";
	std::cout << "Point class has const private variables." << std::endl;
#endif
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
