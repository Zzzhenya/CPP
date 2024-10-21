#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
    public:
        PhoneBook(void);
        void    add_contact(Contact contact);
        int     get_count(void);
        void    init_phonebook(void);
        int     extract_contact(void);
        void    retrieve_phonebook(void);
        void    search_by_index(void);
        void    show_contact_details(std::string input);
        int     loc;
    private:
        Contact contacts[8];
        int     contact_count;
};

#endif