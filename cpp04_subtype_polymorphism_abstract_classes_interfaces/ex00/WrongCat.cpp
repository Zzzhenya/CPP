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

// void    WrongCat::makeSound(void) const
// {
//     std::cout << this->type << " ";
//     std::cout << "makes wrong cat sounds." << std::endl;
// }
