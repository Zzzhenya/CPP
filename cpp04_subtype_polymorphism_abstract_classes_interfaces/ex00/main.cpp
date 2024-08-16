/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:59:06 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 19:54:42 by sde-silv         ###   ########.fr       */
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

void   print_seperator(std::string opt)
{
    if (opt.empty())
        std::cout << "=================" << std::endl;
    else
        std::cout << "================= " << opt << std::endl;
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

void    cat_tests(std::string name)
{
    int i = 1;
    {
        print_no(&i, name, "Default Constructor");
        Cat ct;
    }
    {
        WrongCat ct;
    }
    {
        print_no(&i, name, "Copy Constructor");
        Cat ct;
        Cat *ct1 = new Cat(ct);
        ct1->makeSound();
        delete ct1;
    }
    {
        WrongCat ct;
        WrongCat *ct1 = new WrongCat(ct);
        ct1->makeSound();
        delete ct1;        
    }
    {
        print_no(&i, name, "Copy assignment overload");
        Cat ct;
        Cat ct1;
        ct = ct1;
    }
    {
        WrongCat ct;
        WrongCat ct1;
        ct = ct1;    
    }
}

void    dog_tests(std::string name)
{
    int i = 1;
    {
        print_no(&i, name, "Default Constructor");
        Dog dg;
    }
    {
        print_no(&i, name, "Copy Constructor");
        Dog dg;
        Dog *dg1 = new Dog(dg);

        dg1->makeSound();

        delete dg1;
    }
    {
        print_no(&i, name, "Copy assignment cat to animal");
        Dog dg;
        Dog dg1;

        dg = dg1;
    }
}

void    animal_cat_tests(std::string name)
{
    int i = 1;
    {
        print_no(&i, name, "Default Constructor");
        Animal aml;

        aml.makeSound();
    }
    {
        print_no(&i, name, "Copy cat to animal");
        Cat ct;
        Animal *aml = new Cat(ct);

        aml->makeSound();
        ct.makeSound();

        delete aml;
    }
    {
        WrongCat ct;
        WrongAnimal *aml = new WrongCat(ct);

        aml->makeSound();
        ct.makeSound();

        delete aml;  
    }
    {
        print_no(&i, name, "Copy assignment cat to animal");
        Cat ct;
        Animal aml;

        ct.makeSound();
        aml.makeSound();
        aml = ct;
        ct.makeSound();
        aml.makeSound();
    }
    {
        WrongCat ct;
        WrongAnimal aml;

        ct.makeSound();
        aml.makeSound();
        aml = ct;
        ct.makeSound();
        aml.makeSound();
    }

}

void    animal_dog_tests(std::string name)
{
    int i = 1;
    {
        print_no(&i, name, "Default Constructor");
        Animal aml;

        aml.makeSound();
    }
    {
        print_no(&i, name, "Copy cat to animal");
        Dog ct;
        Animal *aml = new Dog(ct);

        aml->makeSound();
        ct.makeSound();

        delete aml;
    }
    {
        print_no(&i, name, "Copy assignment cat to animal");
        Dog ct;
        Animal aml;

        ct.makeSound();
        aml.makeSound();
        aml = ct;
        ct.makeSound();
        aml.makeSound();
    }

}

void    subject_tests(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
}

void    wrong_subject_tests(void)
{
    print_seperator("WrongAnimal * = new WrongAnimal()");
    {
        const WrongAnimal* meta = new WrongAnimal();
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound();
        delete meta;
    }
    print_seperator("WrongAnimal * = new WrongCat()");
    {
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the wrong animal sound!
        delete i;
    }
    print_seperator("WrongCat * = new WrongCat()");
    {
        const WrongCat* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the wrong cat sound!
        delete i;
    }
    print_seperator(" WrongCat i");
    {
        const WrongCat i;
        std::cout << i.getType() << " " << std::endl;
        i.makeSound(); //will output the wrong cat sound!
    }
    print_seperator(" WrongAnimal i");
    {
        const WrongAnimal i;
        std::cout << i.getType() << " " << std::endl;
        i.makeSound(); //will output the wrong animal sound!
    }
    print_seperator(" WrongAnimal *meta new WrongAnimal() = WrongCat *i new WrongCat()");
    {
        WrongAnimal *meta = new WrongAnimal();
        WrongCat     *i = new WrongCat();
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //will output the wrong animal sound!
        (*meta)=(*i);
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //will output the wrong animal sound!
        delete meta;
        delete i;
    }
    print_seperator(" Animal meta = Cat i");
    {
        Animal *meta = new Animal();
        Cat     *i = new Cat();
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //Animal makes animal sound.
        (*meta)=(*i);
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //Cat makes animal sound.
        delete meta;
        delete i;
    }
    print_seperator(" Animal *meta = new Cat(*i)");
    {
        Animal *meta = new Animal();
        Cat     *i = new Cat();
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //Animal makes animal sound.
        delete meta;
        meta = new Cat(*i);
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound(); //Cat meows.
        delete meta;
        delete i;
    }
    
}

void unit_tests(void)
{
    animal_tests("Animal");
    cat_tests("\tCat");
    dog_tests("\tDog");
    animal_cat_tests("Animal-cat");
    animal_dog_tests("Animal-dog");
}

int main (void)
{
    int val = 1;
    
    std::cout << std::endl;
    print_no(&val, "Unit tests", "");
    std::cout << std::endl;
    unit_tests();

    std::cout << std::endl;
    print_no(&val, "Subject tests", "");
    std::cout << std::endl;
    subject_tests();

    std::cout << std::endl;
    print_no(&val, "Wrong Cat Subject tests", "");
    std::cout << std::endl;
    wrong_subject_tests();
    return (0);    
}