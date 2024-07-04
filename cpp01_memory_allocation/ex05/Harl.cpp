#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
    std::cout << "Harl constructed.\n";
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
    int     ret = getIndex(level);
    void    (Harl::*func[5])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error,
        &Harl::unknown
    };

    (this->*func[ret])();  
}

void    Harl::unknown(void)
{
    std::cout << "Unknown level: \tSeriously, where is the manager?\n";
}

void    Harl::debug(void)
{
    std::cout << "DEBUG level: \t";
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << "I really do!\n";
}

void    Harl::info(void)
{
    std::cout << "INFO level:\t";
    std::cout << "I cannot believe adding extra bacon ";
    std::cout << "costs more money. You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!\n";
}

void    Harl::warning(void)
{
    std::cout << "WARNING level: \t";
    std::cout << "I think I deserve to have some extra bacon ";
    std::cout << "for free. I’ve been coming for years whereas you ";
    std::cout << "started working here since last month.\n";
}

void    Harl::error(void)
{
    std::cout << "ERROR level: \t";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}