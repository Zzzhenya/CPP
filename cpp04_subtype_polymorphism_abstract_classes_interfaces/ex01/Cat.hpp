#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat& other);
        Cat&    operator=(const Cat& other);
    
        void        makeSound(void) const;
    
    private:
        Brain   brain;
};

#endif