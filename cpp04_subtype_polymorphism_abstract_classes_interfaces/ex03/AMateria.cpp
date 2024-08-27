/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 22:09:00 by sde-silv         ###   ########.fr       */
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
AMateria::AMateria(void): _type("materia")
{
	debug(std::cout << "AMateria default constructor\n");
}

AMateria::~AMateria(void)
{
	debug(std::cout << "AMateria destructor\n");
}

AMateria::AMateria(const AMateria &other): _type(other._type)
{
	debug(std::cout << "AMateria copy constructor\n");
}

/**
 * Copy assignment is non-functional and private
 * Making a deep copy causes memory leaks
 * delete this ?
 * return (*other.clone())
*/
AMateria &AMateria::operator=(const AMateria &other)
{
	debug(std::cout << "AMateria copy assignment\n");
	this->_type = other._type;
	return (*this);
}

/**
 * Amateria constructor with _type
 */
AMateria::AMateria(std::string const & type): _type(type)
{
	debug(std::cout << "AMateria type constructor\n");
}

/**
 * Getter for _type
 * Returns the materia type
 */
std::string const &AMateria::getType() const 
{
	debug(std::cout << "AMateria getType member function\n");
	return(this->_type);
}

/**
 * Non functional non-pure virtual function 
 */
void AMateria::use(ICharacter& target)
{
	debug(std::cout << "AMateria use member function\n");
	(void)target;
}
