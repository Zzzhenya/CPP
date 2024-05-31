#include "PhoneBook.hpp"

void    PhoneBook::retrieve_phonebook(void)
{
	std::string str;

	std::cout << "|" << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" <<  "|" << std::endl;
	for (int i = 0; i < this->get_count(); i ++)
	{
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		str = this->contacts[i].getname();
		if (str.length() > 10)
		{
			str.resize(9 , ' ');
			str = str + ".";
		}
		std::cout << std::right << std::setw(10) << str << "|";
		str = this->contacts[i].getlast_name();
		if (str.length() > 10)
		{
			str.resize(9 , ' ');
			str = str + ".";
		}
		std::cout << std::right << std::setw(10) << str << "|";
		str = this->contacts[i].getnickname();
		if (str.length() > 10)
		{
			str.resize(9 , ' ');
			str = str + ".";
		}
		std::cout << std::right << std::setw(10) << str << "|"<< std::endl;
	}
}

void	PhoneBook::show_contact_details(std::string input)
{
	int i;

	i = std::stoi(input);
	std::cout << "index \t\t: "<< i << std::endl;
	std::cout << "first name \t: "<< this->contacts[i].getname() << std::endl;
	std::cout << "last name \t: "<< this->contacts[i].getlast_name() << std::endl;
	std::cout << "nickname \t: "<< this->contacts[i].getnickname() << std::endl;
	std::cout << "phone number \t: "<< this->contacts[i].getphone_number() << std::endl;
	std::cout << "darkest secret \t: "<< this->contacts[i].getsecret() << std::endl;
}

void	PhoneBook::search_by_index(void)
{
	std::string input;

	std::cout << "Type the index of the contact" << std::endl;
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]) && input[0] < std::to_string(get_count())[0])
		show_contact_details(input);
	else
		std::cout << "Index out of range" << std::endl;
    
}