/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:38:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    this->type = "Animal";
    std::cout << "Animal default constructor called." << std::endl;
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal destructor called." << std::endl;
}

//Copy constructor
Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called." << std::endl;
    this->type = other.type;
}

//Copy constructor overload
Animal&     Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy constructor overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "makes animal sound." << std::endl;
}

std::string    Animal::getType(void) const
{
    return (this->type);
}