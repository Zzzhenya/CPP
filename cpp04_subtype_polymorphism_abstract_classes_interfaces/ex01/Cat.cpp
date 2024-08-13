/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:03:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 12:21:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    this->setIdeas("I am a Catt");
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    this->brain = other.brain;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment overload called." << std::endl;
    this->type = other.type;
    this->brain = other.brain;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "meows." << std::endl;
}

std::string *Cat::getIdeas(void)
{
    return (Brain::getIdeas());
}

void    Cat::setIdeas(std::string new_idea)
{
    Brain::setIdeas(new_idea);
}