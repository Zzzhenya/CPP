/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 20:10:35 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    this->setIdeas ("Normal dog ideas");
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string new_idea): Animal()
{
    //this->type = "Dog";
    this->brain = new Brain();
    this->setIdeas (new_idea);
    std::cout << "Dog idea constructor called." << std::endl;
}

// Destructor
Dog::~Dog(void)
{
    delete this->brain;
    std::cout << "Dog destructor called." << std::endl;
}

// Copy consrtuctor
Dog::Dog(const Dog& other): Animal(other)
{
    this->brain = new Brain();
    const std::string *temp = other.getIdeas();
    this->brain->setIdeas(temp[0]);
    std::cout << "Dog copy constructor called." << std::endl;
}

// Copy assignment operator overload
Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator overload called." << std::endl;
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain();
    const std::string *temp = other.getIdeas();
    this->brain->setIdeas(temp[0]);
    return (*this);
}

// makeSound member function
void    Dog::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "barks." << std::endl;
}

const std::string *Dog::getIdeas(void) const
{
    return (this->brain->getIdeas());
}

void    Dog::setIdeas(std::string new_idea)
{
    this->brain->setIdeas(new_idea);
}