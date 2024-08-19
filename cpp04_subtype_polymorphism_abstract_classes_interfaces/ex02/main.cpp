/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:02 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/19 19:26:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define ARRLEN 4

void    print_no(int *i, std::string name, std::string detail)
{
    std::cout << "======" << "Test: ";
    if (i)
        std::cout << *i << (" " + name);
    else
        std::cout << (" " + name);
    std::cout << "======\t\t" << detail << std::endl;
    if (i)
        (*i) += 1;
}

void    subject_tests(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;
}

void    animal_array_tests(void)
{
    int val = 1;
    print_no(&val, "Deep Copy", "In a loop");
    {
        Animal *animals[ARRLEN];
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
        Animal *animals[4] = {one, two, three, four};
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

void brain_tests(void)
{
    {
        Cat one;
        const std::string *ideas;
        int i = 0;

        ideas = one.getIdeas();
        while (i < IDEA_LIMIT)
        {
            std::cout << ideas[i] << std::endl;
            i ++;
        }
    }
    {
        Dog one;
        const std::string *ideas;
        int i = 0;

        ideas = one.getIdeas();
        while (i < IDEA_LIMIT)
        {
            std::cout << ideas[i] << std::endl;
            i ++;
        }
        one.setIdeas("HAHAHAHA");
        i = 0;
        ideas = one.getIdeas();
        while (i < IDEA_LIMIT)
        {
            std::cout << ideas[i] << std::endl;
            i ++;
        }
    }
    {
        
    }
}

void    print_ideas(const std::string *ideas)
{
    for (int i = 0; i < IDEA_LIMIT; i++)
    {
        std::cout << ideas[i] << std::endl;
    }
}

void    deep_copy_tests(void)
{
    print_no(NULL, "Basic", "Dog");
    {
        Dog basic;
        {
            Dog tmp = basic;
        }
    }
    print_no(NULL, "Basic", "Cat");
    {
        Cat basic;
        {
            Cat tmp = basic;
        }
    }
    print_no(NULL, "Idea copy", "Dog");
    {
        const std::string *basic_i = NULL;
        Dog basic("HAHA");
        basic_i = basic.getIdeas();
        print_ideas(basic_i);
        {
            const std::string *tmp_i = NULL;
            Dog tmp = basic;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
        }
    }
    print_no(NULL, "Idea copy", "Cat");
    {
        const std::string *basic_i = NULL;
        Cat basic("HAHA");
        basic_i = basic.getIdeas();
        print_ideas(basic_i);
        {
            const std::string *tmp_i = NULL;
            Cat tmp = basic;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
        }
    }
    print_no(NULL, "Basic - Copy Assignment", "Dog");
    {
        Dog basic;
        {
            Dog tmp;
            tmp = basic;
        }
    }
    print_no(NULL, "Basic - Copy Assignment", "Cat");
    {
        Cat basic;
        {
            Cat tmp;
            tmp = basic;
        }
    }
    print_no(NULL, "Idea copy - Copy Assignment", "Dog");
    {
        const std::string *basic_i = NULL;
        Dog basic("HAHA");
        basic_i = basic.getIdeas();
        print_ideas(basic_i);
        {
            const std::string *tmp_i = NULL;
            Dog tmp;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
            tmp = basic;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
        }
    }
    print_no(NULL, "Idea copy - Copy Assignment", "Cat");
    {
        const std::string *basic_i = NULL;
        Cat basic("HAHA");
        basic_i = basic.getIdeas();
        print_ideas(basic_i);
        {
            const std::string *tmp_i = NULL;
            Cat tmp;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
            tmp = basic;
            tmp_i = tmp.getIdeas();
            print_ideas(tmp_i);
        }
    }
}

void    animal_tests(std::string name)
{
    int i = 1;
    {
        print_no(&i, name, "Default Constructor");
        Animal      aml;
        WrongAnimal waml;
    }
    {
        print_no(&i, name, "Copy Constructor");
        Animal      aml;
        Animal *aml1 = new Animal(aml);
        aml1->makeSound();
        delete aml1;
    }
    {
        WrongAnimal waml;
        WrongAnimal *waml1 = new WrongAnimal(waml);
        waml1->makeSound();
        delete waml1;
    }
    {
        print_no(&i, name, "Copy assignment overload");
        Animal aml;
        Animal aml1;
        aml = aml1;
    }
    {
        WrongAnimal aml;
        WrongAnimal aml1;
        aml = aml1;
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

    std::cout << std::endl;
    print_no(&val, "Brain tests", "");
    std::cout << std::endl;
    brain_tests();

    std::cout << std::endl;
    print_no(&val, "Deep Copy tests", "");
    std::cout << std::endl;
    deep_copy_tests();

    // animal_tests("Animal");

    return (0);    
}