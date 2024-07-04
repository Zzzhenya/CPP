#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
}

size_t  Harl::getIndex(std::string level)
{
    int i = 0;

    while (i < 4)
    {
        if (!level.compare(this->levels[i]))
            return (i);
        i ++;
    }
    return (4);
}

std::string Harl::getLevel(size_t index)
{
    switch(index)
    {
        case 0:
            return (this->levels[0]);
        case 1:
            return (this->levels[1]);
        case 2:
            return (this->levels[2]);
        case 3:
            return (this->levels[3]);
        default:
            return ("Out of bounds");
    }
}

void    Harl::complain(std::string level)
{
    // int     ret = getIndex(level);
    void    (Harl::*func[5])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error,
        &Harl::unknown
    };

    switch(getIndex(level))
    {
        case 0:
            (this->*func[0])();
        case 1:
            (this->*func[1])();
        case 2:
            (this->*func[2])();
        case 3:
            (this->*func[3])();
            break;
        case 4:
            (this->*func[4])();
    }

}

void    Harl::unknown(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << "I really do!\n";
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon ";
    std::cout << "costs more money. You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!\n";
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon ";
    std::cout << "for free. I’ve been coming for years whereas you ";
    std::cout << "started working here since last month.\n";
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}