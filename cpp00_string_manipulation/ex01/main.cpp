#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook new_book;
    // Contact new_contact;

    // new_contact.name ;
    // Contact newContact;

    // newContact.name = "a";
    // newContact.number = "123";

    // std::cout << newContact.name << std::endl;
    // std::cout << newContact.number << std::endl;

    
    new_book.init_phonebook();
    //     else if (str.compare("ADD") == 0)
    //         std::cout << "ADD" << str << std::endl;
    //     else if (str.compare("SEARCH") == 0)
    //         std::cout << "SEARCH" << str << std::endl;
    //     else
    //         std::cout << str << std::endl;
    // } 
    new_book.print_contacts();
    new_book.~PhoneBook();
    return (0);
}