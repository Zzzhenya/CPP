#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment overload called." << std::endl;
    this->type = other.type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->type << " ";
    std::cout << "meows." << std::endl;
}
