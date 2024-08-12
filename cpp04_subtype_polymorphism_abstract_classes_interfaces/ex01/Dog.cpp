/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:03:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:38:15 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "barks." << std::endl;
}