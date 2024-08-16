/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 20:11:16 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void) : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    this->setIdeas("Normal cat ideas");
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string new_idea): Animal()
{
    //this->type = "Cat";
    this->brain = new Brain();
    this->setIdeas (new_idea);
    std::cout << "Cat idea constructor called." << std::endl;
}

// Destructor
Cat::~Cat(void)
{
    delete this->brain;
    std::cout << "Cat destructor called." << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other): Animal(other)
{
    this->brain = new Brain();
    const std::string *temp = other.getIdeas();
    this->brain->setIdeas(temp[0]);
    std::cout << "Cat copy constructor called." << std::endl;
}

// Copy assignment operator overload
Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator overload called." << std::endl;
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain();
    const std::string *temp = other.getIdeas();
    this->brain->setIdeas(temp[0]);
    return (*this);
}

// makeSound member function
void    Cat::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "meows." << std::endl;
}

const std::string *Cat::getIdeas(void) const
{
    return (this->brain->getIdeas());
}

void    Cat::setIdeas(std::string new_idea)
{
    this->brain->setIdeas(new_idea);
}