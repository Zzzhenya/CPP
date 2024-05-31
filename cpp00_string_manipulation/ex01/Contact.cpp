#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string c_name, std::string c_lname, std::string c_num)
{
	this->name = c_name;
	this->last_name = c_lname;
	this->phone_number = c_num;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getname(void)
{
	return (this->name);
}

std::string Contact::getlast_name(void)
{
	return (this->last_name);
}

std::string Contact::getphone_number(void)
{
	return (this->phone_number);
}