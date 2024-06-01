#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
	this->loc = 0;
	return ;
}

int     PhoneBook::get_count(void)
{
	return (this->contact_count);
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

std::string get_val(std::string label, std::string val)
{
	while (val.length() == 0)
	{
		std::cout << label;
		std::getline(std::cin, val);
	}
	return (val);
}

void PhoneBook::extract_contact(void)
{
	std::string	first_name;
	std::string last_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;

	first_name = get_val("first name: ", first_name);
	last_name = get_val("last name: ", last_name);
	nickname = get_val("nickname: ", nickname);
	phone_number = get_val("phone number: ", phone_number);
	darkest_secret = get_val("darkest secret: ", darkest_secret);
    this->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

void PhoneBook::init_phonebook(void)
{
	std::string str;

	std::cout << "\n\tWelcome to Phonebook!" << std::endl << std::endl;
    while (1)
    {
        std::cout << "You can type ADD,SEARCH or EXIT: ";
        std::getline(std::cin, str);
        if (str.compare("EXIT") == 0)
            break;
        else if (str.compare("SEARCH") == 0)
        {
        	if (this->get_count() > 0)
        	{
        		retrieve_phonebook();
        		search_by_index();
        	}
        	else
        		std::cout << "Phonebook is empty" << std::endl;
        }
        else if (str.compare("ADD") == 0)
        	extract_contact();
    }
}