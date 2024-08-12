/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:02 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 20:00:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define ARRLEN 4

void    print_no(int *i, std::string name, std::string detail)
{
    std::cout << "======" << "Test: ";
    std::cout << *i << (" " + name);
    std::cout << "======\t\t" << detail << std::endl;
    (*i) += 1;
}

void    subject_tests(void)
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;
}

void    animal_array_tests(void)
{
    int val = 1;
    /*
    print_no(&val , "Surface Copy", "");
    {
        Cat one;
        Cat two;
        Dog three;
        Dog four;
        Animal animals[4] = {one, two, three, four};
        int i = 0;

        while (i < 4)
        {
            animals[i].makeSound();
            i ++;
        }
    }
    std::cout << std::endl;*/
    print_no(&val, "Deep Copy", "In a loop");
    {
        AAnimal *animals[ARRLEN];
        int i = 0;

        while (i < ARRLEN)
        {
            if (i < ARRLEN/2)
                animals[i] = new Cat();
            else
                animals[i] = new Dog();
            i ++;
        }
        i = 0;

        while (i < ARRLEN)
        {
            animals[i]->makeSound();
            i ++;
        }
        i = 0;

        while (i < ARRLEN)
        {
            delete animals[i];
            i ++;
        }
    }
    std::cout << std::endl;
    print_no(&val, "Deep Copy", "Manual");
    {
        Cat *one = new Cat();
        Cat *two = new Cat();
        Dog *three = new Dog();
        Dog *four = new Dog();
        AAnimal *animals[4] = {one, two, three, four};
        int i = 0;

        while (i < 4)
        {
            animals[i]->makeSound();
            i ++;
        }

        i = 0;
        while (i < 4)
        {
            delete animals[i];
            i ++;
        }
    }
}

int main (void)
{
    int val = 1;

    std::cout << std::endl;
    print_no(&val, "Subject tests", "");
    std::cout << std::endl;
    subject_tests();

    std::cout << std::endl;
    print_no(&val, "Animal array tests", "");
    std::cout << std::endl;
    animal_array_tests();

    return (0);    
}