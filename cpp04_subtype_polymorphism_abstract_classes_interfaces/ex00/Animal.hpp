#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    public:
        Animal(void);
        ~Animal(void);
        Animal(const Animal& other);
        Animal&     operator=(const Animal& other);
        Animal(const std::string type);

    protected:
        std::string type;
};

#endif