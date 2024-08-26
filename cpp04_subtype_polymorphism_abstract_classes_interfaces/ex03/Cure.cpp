/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:35 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/26 23:11:45 by sde-silv         ###   ########.fr       */
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

Cure &Cure::operator=(const Cure &other)
{
    debug(std::cout << "Cure copy assignment\n");
    (void)other;
    // this->_type = other._type;
    return (*this);
}

Cure*	Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

void Cure::use(ICharacter& target)
{
    //else if (this->_inventory[idx]->getType() == TYPE_CURE)
    {
        std::cout << "Cure: \"* heals ";
        std::cout << target.getName();
        std::cout << "’s wounds *\"" << std::endl;
    }
}