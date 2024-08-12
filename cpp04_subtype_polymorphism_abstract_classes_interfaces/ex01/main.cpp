/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:02 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:37:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    print_no(int *i, std::string name, std::string detail)
{
    std::cout << "======" << "Test: ";
    std::cout << *i << (" " + name);
    std::cout << "======\t\t" << detail << std::endl;
    (*i) += 1;
}

void    subject_tests(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;
}

int main (void)
{
    int val = 1;

    std::cout << std::endl;
    print_no(&val, "Subject tests", "");
    std::cout << std::endl;
    subject_tests();

    return (0);    
}