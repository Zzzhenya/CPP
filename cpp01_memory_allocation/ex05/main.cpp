#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl one;
    int i = -1;
    
    while (i < 10)
    {
        one.complain("DEBUG");
        i ++;
    }
    return (0);
}