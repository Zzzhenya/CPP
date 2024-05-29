#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add_contact(Contact contact);
        int     get_count(void);
        void    print_contacts(void);
        int     loc;
    private:
        Contact contacts[8];
        int     contact_count;
};

#endif