#include <iostream>
#include <string>
#include "Contact.hpp"

int main(void)
{
    Contact newContact;

    newContact.name = "a";
    newContact.number = "123";

    std::cout << newContact.name << std::endl;
    std::cout << newContact.number << std::endl;

    // std::string str;
    // init_new_phonebook();
    // while (1)
    // {
    //     std::cout << "Phonebook" << std::endl;
    //     std::cout << "ADD . SEARCH . EXIT" << std::endl;
    //     std::cin >> str;
    //     if (str.compare("EXIT") == 0)
    //         break;
    //     else if (str.compare("ADD") == 0)
    //         std::cout << "ADD" << str << std::endl;
    //     else if (str.compare("SEARCH") == 0)
    //         std::cout << "SEARCH" << str << std::endl;
    //     else
    //         std::cout << str << std::endl;
    // } 
    return (0);
}