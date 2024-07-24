#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    std::cout << "Animal default constructor called." << std::endl;
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal destructor called." << std::endl;
}

//Copy constructor
Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called." << std::endl;
}

//Copy constructor overload
Animal&     Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy constructor overload called." << std::endl;
}

// Constructor with type input
Animal::Animal(const std::string type)
{
    std::cout << "Animal constructor called." << std::endl;
}