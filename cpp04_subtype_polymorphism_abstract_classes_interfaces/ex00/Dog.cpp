/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 16:06:59 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog destructor called." << std::endl;
}

// Copy consrtuctor
Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

// Copy assignment operator overload
Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

// makeSound member function
void    Dog::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "barks." << std::endl;
}