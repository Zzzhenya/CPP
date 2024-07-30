/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:17:11 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 17:09:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Default constructor that initialized fixed_val to zero
*/
Fixed::Fixed(void)
{
	std::cout << "Default constructor called.\n";
	this->fixed_val = 0;
}

/* 
	Destructor
*/
Fixed::~Fixed(void)
{
	std::cout << "Destructor called.\n";
}

/*
	Copy constructor
	alternative: 
		(*this) = other;
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called.\n";
	fixed_val = other.getRawBits();
}

/* 
	A copy assignment operator overload.
	alternative:
		fixed_val = other.fixed_val;
*/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called.\n";
	fixed_val = other.getRawBits();
	return (*this);
}

/*
	member function that 
	returns the raw value of the fixed-point value.
*/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits" << " member function called.\n";
	return (this->fixed_val);
}

/*
	member function that 
	sets the raw value of the fixed-point number
*/
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits" << " member function called.\n";
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
	std::cout << "Int constructor called.\n";
	this->fixed_val = number << this->fract;
}

/*
	Float constructor
	alternative:
		this->fixed_val = roundf(number * pow(2, this->fract));
*/
Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called.\n";
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
