/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:39:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

