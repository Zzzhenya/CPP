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