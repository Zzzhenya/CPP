#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string c_name)
{
	name = c_name;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getName(void)
{
	return (this->name);
}