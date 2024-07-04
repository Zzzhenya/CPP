#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl one;

    if (argc != 2)
    {
        std::cerr << "Enter a filter: DEBUG, WARNING, INFO or ERROR.\n";
        return (1);
    }
    one.complain(argv[1]);
    return (0);
}
