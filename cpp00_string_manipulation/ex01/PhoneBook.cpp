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
		if (std::cin.eof())
			break;
	}
	return (val);
}

int PhoneBook::extract_contact(void)
{
	std::string	first_name;
	std::string last_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;

	first_name = get_val("first name: ", first_name);
	if (first_name.length() == 0)
		return (0);
	last_name = get_val("last name: ", last_name);
	if (last_name.length() == 0)
		return (0);
	nickname = get_val("nickname: ", nickname);
	if (last_name.length() == 0)
		return (0);
	phone_number = get_val("phone number: ", phone_number);
	if (last_name.length() == 0)
		return (0);
	darkest_secret = get_val("darkest secret: ", darkest_secret);
	if (last_name.length() == 0)
		return (0);
    this->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
	return (1);
}

void PhoneBook::init_phonebook(void)
{
	std::string str;

	std::cout << "\n\tWelcome to Phonebook!" << std::endl << std::endl;
    while (1)
    {
        std::cout << "You can type ADD,SEARCH or EXIT" << std::endl;
        std::getline(std::cin, str);
        if (str.compare("EXIT") == 0 || std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "exiting..." << std::endl;
            break;
		}
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
		{
        	if (!extract_contact())
			{
				std::cout << std::endl;
				std::cout << "exiting..." << std::endl;
				break;
			}
		}
    }
}