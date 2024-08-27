/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:42 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 15:58:25 by sde-silv         ###   ########.fr       */
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
    debug(std::cout << "Ice default constructor\n");
}

Ice::~Ice(void)
{
    debug(std::cout << "Ice destructor\n");
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    debug(std::cout << "Ice copy constructor\n");
}

/**
 * Ice copy assignment can only copy another ice object
 * Ice objects only have type variable set to "ice"
 *  therefore : no need to copy the type
 */
Ice     &Ice::operator=(const Ice &other)
{
    debug(std::cout << "Ice copy assignment\n");
    (void)other;
    return (*this);
}

/**
 *  Member function clone
 */
Ice*    Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

/**
 *  Member function use
 */
void    Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at ";
    std::cout << target.getName();
    std::cout << " *\"" << std::endl;
}