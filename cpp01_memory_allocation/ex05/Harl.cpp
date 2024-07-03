#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
    std::cout << "Created\n";
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
    return (5);
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
    int ret = getIndex(level);

    switch(ret)
    {
        case 5:
            std::cout << "OUT OF BOUNDS\n";
            break;
        case 0:
            debug();
            break;
        case 1:
            info();
            break;
        case 2:
            warning();
            break;
        case 3:
            error();
            break;
        default:
            std::cout << "Mistake!\n";
            break;
    }
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << "I really do!\n";
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon ";
    std::cout << "costs more money. You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!\n";
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon ";
    std::cout << "for free. I’ve been coming for years whereas you ";
    std::cout << "started working here since last month.\n";
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}