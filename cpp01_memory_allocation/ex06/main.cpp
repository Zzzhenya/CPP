#include "Harl.hpp"
#include <iostream>

// void    harl_filter(std::string filter)
// {
//     Harl one;


//     switch (one.getIndex(filter))
//     {
//         case 0:
//             one.complain("DEBUG");
//         case 1:
//             one.complain("INFO");
//         case 2:
//             one.complain("WARNING");
//         case 3:
//             one.complain("ERROR");
//             break;
//         default:
//             std::cout << "[ Probably complaining about insignificant problems ]\n";
//     }
// }

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Enter a filter: DEBUG, WARNING, INFO or ERROR.\n";
        return (1);
    }
    Harl one;
    one.complain(argv[1]);
    // harl_filter(argv[1]);
    return (0);
}
