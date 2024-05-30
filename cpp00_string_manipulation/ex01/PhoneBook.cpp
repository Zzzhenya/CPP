#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
	this->loc = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int     PhoneBook::get_count(void)
{
	return (this->contact_count);
}

void    PhoneBook::print_contacts(void)
{
	std::cout << this->get_count() << std::endl;
	for (int i = 0; i < this->get_count(); i ++)
	{
		std::cout << this->contacts[i].getName() << std::endl;
	}
}

void    PhoneBook::add_contact(Contact contact)
{
	if (this->get_count() < 8)
	{
		this->contacts[this->get_count()] = contact;
		this->contact_count ++;
	}
	else
	{
		this->contacts[this->loc] = contact;
		if (this->loc == 7)
			this->loc = 0;
		else
			this->loc++;
	}
}

void PhoneBook::init_phonebook(void)
{
	std::string str;
    while (1)
    {
        std::cout << "Phonebook" << std::endl;
        std::cout << "ADD . SEARCH . EXIT" << std::endl;
        std::cin >> str;
        if (str.compare("EXIT") == 0)
            break;
        else
        {
            this->add_contact(Contact(str));
        }
    }
}