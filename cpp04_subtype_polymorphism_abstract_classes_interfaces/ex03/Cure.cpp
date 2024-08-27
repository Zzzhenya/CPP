/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:35 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 22:11:32 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/**
 * Orthodox canonical form functions
 * 
 * 1. Default constructor
 * 2. Destructor
 * 3. Copy constructor
 * 4. Copy assignment operator overload
 */

Cure::Cure(void) : AMateria(TYPE_CURE)
{
    debug(std::cout << "Cure default constructor\n");
}

Cure::~Cure(void)
{
    debug(std::cout << "Cure destructor\n");
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    debug(std::cout << "Cure copy constructor\n");
}

/**
 * Cure copy assignment can only copy another Cure object
 * Cure objects only have type variable already set to "cure"
 *  therefore : no need to copy the type
 */
Cure &Cure::operator=(const Cure &other)
{
    debug(std::cout << "Cure copy assignment\n");
    (void)other;
    return (*this);
}

/**
 *  member function clone
 */
Cure*	Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

/**
 *  member function use
 */
void Cure::use(ICharacter& target)
{
    std::cout << "Cure: \"* heals ";
    std::cout << target.getName();
    std::cout << "’s wounds *\"" << std::endl;
}
