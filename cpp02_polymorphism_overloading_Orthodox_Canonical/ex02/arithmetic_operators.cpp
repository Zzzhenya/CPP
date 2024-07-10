#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed& second)
{
	Fixed ret;

	ret.setRawBits(this->fixed_val + second.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed& second)
{
	Fixed ret;

	ret.setRawBits(this->fixed_val - second.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed& second)
{
	Fixed ret;

	//ret.setRawBits(this->fixed_val * second.getRawBits());
	ret.setRawBits((this->fixed_val * second.getRawBits())/(pow(2, this->fract)));
	return (ret);
}

Fixed Fixed::operator/(const Fixed& second)
{
	Fixed ret;

	//ret.setRawBits(this->fixed_val / second.getRawBits());
	ret.setRawBits((this->fixed_val / second.getRawBits())*(pow(2, this->fract)));
	return (ret);
}