/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 16:26:41 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called." << std::endl;
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called." << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

// Copy assignment operator overload
WrongCat&    WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "makes wrong animal sound." << std::endl;
}
