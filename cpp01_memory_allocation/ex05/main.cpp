#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl one;
    int i = -1;
    
    while (i < 10)
    {
        //std::cout << one.getLevel(i) << ":\t";
        one.complain(one.getLevel(i));
        i ++;
    }
    return (0);
}