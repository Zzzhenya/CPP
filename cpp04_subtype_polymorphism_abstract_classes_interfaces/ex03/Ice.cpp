/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:42 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/20 11:17:18 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/**
 * Orthodox canonical form functions
 * 
 * 1. Default constructor
 * 2. Destructor
 * 3. Copy constructor
 * 4. Copy assignment operator overload
 */

Ice::Ice(void) : AMateria(TYPE_ICE)
{
    std::cout << "Ice default constructor\n";
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << "Ice copy constructor\n";
}

// Ice Ice::operator=(const Ice &other)
// {

// }

Ice*	Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}