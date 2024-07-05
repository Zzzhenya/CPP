#include "Fixed.hpp"

// Default constructor that initialized fixed_val to zero
Fixed::Fixed(void)
{
	this->fixed_val = 0;
	std::cout << "Default constructor called.\n";
}

// Copy constructor
Fixed::Fixed(Fixed& other)
{
	fixed_val = other.getRawBits();
	std::cout << "Copy constructor called.\n";
}

//A copy assignment operator overload.
Fixed& Fixed::operator=(Fixed& other)
{
	fixed_val = other.getRawBits();
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

//A destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called.\n";
}

//A member function int getRawBits( void ) const;
//that returns the raw value of the fixed-point value.
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits" << " member function called.\n";
	return(this->fixed_val);
}

// A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits" << " member function called.\n";
	this->fixed_val = raw;
}
