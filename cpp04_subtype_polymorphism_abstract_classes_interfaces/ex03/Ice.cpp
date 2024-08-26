/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:42 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/26 14:03:06 by sde-silv         ###   ########.fr       */
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

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice copy assignment\n";
    (void)other;
    // this->_type = other._type;
    return (*this);
}

Ice*	Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at ";
    std::cout << target.getName();
    std::cout << " *\"" << std::endl;
}