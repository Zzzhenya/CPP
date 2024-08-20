/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/20 11:19:25 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/**
 * Orthodox canonical form functions
 * 
 * 1. Default constructor
 * 2. Destructor
 * 3. Copy constructor
 * 4. Copy assignment operator overload
 */
AMateria::AMateria(void)
{
	_type = "";
	std::cout << "AMateria default constructor\n";
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor\n";
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor\n";
	this->_type = other._type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment\n";
	this->_type = other._type;
	return (*this);
}

/**
 * Amateria constructor with _type
 */
AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << "AMateria type constructor\n";
}

/**
 * Getter for _type
 */
std::string const &AMateria::getType() const //Returns the materia type
{
	return(this->_type);
}

AMateria*	AMateria::clone() const
{
	AMateria *copy = NULL;
	return (copy);
}

// virtual void use(ICharacter& target);