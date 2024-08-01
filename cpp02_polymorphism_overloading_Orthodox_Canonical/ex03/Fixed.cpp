/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:14:34 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 22:00:02 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Default constructor that initialized fixed_val to zero
*/
Fixed::Fixed(void)
{
#ifdef _DEBUG
#else
	std::cout << "Default constructor called.\n";
#endif
	this->fixed_val = 0;
}

/* 
	Destructor
*/
Fixed::~Fixed(void)
{
#ifdef _DEBUG
#else
	std::cout << "Destructor called.\n";
#endif
}

/*
	Copy constructor
	alternative: 
		(*this) = other;
*/
Fixed::Fixed(const Fixed& other)
{
#ifdef _DEBUG
#else
	std::cout << "Copy constructor called.\n";
#endif
	fixed_val = other.getRawBits();
}

/* 
	A copy assignment operator overload.
	alternative:
		fixed_val = other.fixed_val;
*/
Fixed& Fixed::operator=(const Fixed& other)
{
#ifdef _DEBUG
#else
	std::cout << "Copy assignment operator called.\n";
#endif
	fixed_val = other.getRawBits();
	return (*this);
}

/*
	member function that 
	returns the raw value of the fixed-point value.
*/
int	Fixed::getRawBits(void) const
{
#ifdef _DEBUG
#else
	std::cout << "getRawBits" << " member function called.\n";
#endif
	return (this->fixed_val);
}

/*
	member function that 
	sets the raw value of the fixed-point number
*/
void	Fixed::setRawBits(int const raw)
{
#ifdef _DEBUG
#else
	std::cout << "setRawBits" << " member function called.\n";
#endif
	this->fixed_val = raw;
}

/*
	Integer constructor
	To convert an integer number Num to a fixed point we 
		multiply the number by 2^(n- 1)  : 
			this->fixed_val = number * static_cast<int>(pow(2, this->fract));
		or we left shift the bits by (n - 1) where n is the fractional bits specified.
*/
Fixed::Fixed(const int number)
{
#ifdef _DEBUG
#else
	std::cout << "Int constructor called.\n";
#endif
	this->fixed_val = number << this->fract;
}

/*
	Float constructor
	alternative:
		this->fixed_val = roundf(number * pow(2, this->fract));
*/
Fixed::Fixed(const float number)
{
#ifdef _DEBUG
#else
	std::cout << "Float constructor called.\n";
#endif
	this->fixed_val = roundf(number * (1 << this->fract));
}

/* 
	Converts the fixed point value to an integer value
*/
int		Fixed::toInt(void) const
{
	return(this->fixed_val / static_cast<int>(pow(2, this->fract)));
}

/*
	Converts the fixed point value to it's floating point representation
	alternative? 
		ret = roundf(this->fixed_val / pow(2, this->fract));
*/
float		Fixed::toFloat(void) const
{
	return (this->fixed_val / pow(2, this->fract));
}

/*
	overload of the insertion («) operator 
	that inserts a floating-point representation of the fixed-point number 
	into the output stream object passed as parameter.
*/
std::ostream& operator<<(std::ostream& streamRef, const Fixed& number)
{
	streamRef << number.toFloat();
	return (streamRef);
}

/* 
	post-increment operator : a++
		operator++();
*/
Fixed	Fixed::operator++(int val)
{
	(void)val;
	Fixed tmp(*this);
	(*this).setRawBits(this->fixed_val + 1);
	return (tmp);
}

/*
	pre-increment operator : ++a
*/
Fixed&	Fixed::operator++(void)
{
	(*this).setRawBits(this->fixed_val + 1);
	return (*this);
}

/*
	pre-decrement operator : --a
*/
Fixed&	Fixed::operator--(void)
{
	(*this).setRawBits(this->fixed_val - 1);
	return (*this);
}

/*
	post-decrement operator : a--
		operator--();
*/
Fixed	Fixed::operator--(int val)
{
	(void)val;
	Fixed tmp(*this);
	(*this).setRawBits(this->fixed_val - 1);
	return(tmp);
}

/* 
	A static member function min that takes 
	as parameters two references on fixed-point numbers, and 
	returns a reference to the smallest one.
*/
Fixed&		Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	return (second);
}

/*
	A static member function min that takes 
	as parameters two references to constant fixed-point numbers, 
	and returns a reference to the smallest one.
*/
const Fixed&	Fixed::min(const Fixed &first, const Fixed	&second)
{
	if (first < second)
		return (first);
	return (second);
}

/*
	A static member function max that takes
	as parameters two references on fixed-point numbers,
	and returns a reference to the greatest one.
*/
Fixed&		Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	return (second);
}

/*
	A static member function max that takes 
	as parameters two references to constant fixed-point numbers, 
	and returns a reference to the greatest one.
*/
const Fixed&	Fixed::max(const Fixed &first, const Fixed	&second)
{
	if (first > second)
		return (first);
	return (second);
}

/*	Comparison operators	*/
bool	Fixed::operator>(const Fixed& other) const
{
	if (this->fixed_val > other.fixed_val)
		return (1);
	return (0);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->fixed_val < other.fixed_val)
		return (1);
	return (0);
}

bool	Fixed::operator>=(const Fixed& other)
{
	if (this->fixed_val >= other.fixed_val)
		return (1);
	return (0);
}

bool	Fixed::operator<=(const Fixed& other)
{
	if (this->fixed_val <= other.fixed_val)
		return (1);
	return (0);
}

bool	Fixed::operator==(const Fixed& other)
{
	if (this->fixed_val == other.fixed_val)
		return (1);
	return (0);
}

bool	Fixed::operator!=(const Fixed& other)
{
	if (this->fixed_val != other.fixed_val)
		return (1);
	return (0);
}

/*	Arithmetic Operators	*/

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits(this->fixed_val + other.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits(this->fixed_val - other.getRawBits());
	return (ret);
}

//ret.setRawBits(this->fixed_val * other.getRawBits());
Fixed Fixed::operator*(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits((this->fixed_val * other.getRawBits())/(pow(2, this->fract)));
	return (ret);
}

//ret.setRawBits(this->fixed_val / other.getRawBits());
Fixed Fixed::operator/(const Fixed& other)
{
	Fixed ret;

	ret.setRawBits((this->fixed_val / other.getRawBits())*(pow(2, this->fract)));
	return (ret);
}
