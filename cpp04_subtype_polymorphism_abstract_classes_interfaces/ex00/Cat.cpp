/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 16:11:09 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void) : Animal()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat destructor called." << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

// Copy assignment operator overload
Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

// makeSound member function
void    Cat::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "meows." << std::endl;
}
