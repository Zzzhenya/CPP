/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:39:14 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    this->type = other.type;
}

//Copy constructor overload
WrongAnimal&     WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "makes wrong animal sound." << std::endl;
}

std::string    WrongAnimal::getType(void) const
{
    return (this->type);
}