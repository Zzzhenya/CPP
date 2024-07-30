/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:01:01 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 14:13:28 by sde-silv         ###   ########.fr       */
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
	another implementation: (*this) = other;
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called.\n";
	fixed_val = other.getRawBits();
}

/* 
	A copy assignment operator overload.
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
