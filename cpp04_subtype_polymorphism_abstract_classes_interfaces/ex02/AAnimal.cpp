/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:03:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 20:02:33 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal(void)
{
    this->type = "AAnimal";
    std::cout << "AAnimal default constructor called." << std::endl;
}

// Destructor
AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called." << std::endl;
}

//Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
    std::cout << "AAnimal copy constructor called." << std::endl;
    this->type = other.type;
}

//Copy constructor overload
AAnimal&     AAnimal::operator=(const AAnimal& other)
{
    std::cout << "AAnimal copy constructor overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    AAnimal::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "makes animal sound." << std::endl;
}

std::string    AAnimal::getType(void) const
{
    return (this->type);
}