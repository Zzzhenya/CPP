#include "Fixed.hpp"

// Default constructor that initialized fixed_val to zero
Fixed::Fixed(void)
{
	this->fixed_val = 0;
	std::cout << "Default constructor called.\n";
}

// Integer constructor
//To convert an integer number Num to a fixed point we 
// multiply the number by 2^(n- 1) 
// or we left shift the bits by (n - 1) where n is the fractional bits specified.

Fixed::Fixed(const int number)
{
	this->fixed_val = number << this->fract;
	//this->fixed_val = number * static_cast<int>(pow(2, this->fract));
	std::cout << "Integer constructor called.\n";
}

// Float constructor

Fixed::Fixed(const float number)
{
	this->fixed_val = roundf(number * (1 << this->fract));
	//this->fixed_val = roundf(number * pow(2, this->fract));
	std::cout << "Float constructor called.\n";
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

// Converts the fixed point value to an integer value
int		Fixed::toInt(void) const
{
	int ret = 0;

	ret = this->fixed_val / static_cast<int>(pow(2, this->fract));
	return (ret);
}

float		Fixed::toFloat(void) const
{
	float ret = 0;

	//ret = roundf(this->fixed_val / pow(2, this->fract));
	ret = this->fixed_val / pow(2, this->fract);
	return (ret);
}
