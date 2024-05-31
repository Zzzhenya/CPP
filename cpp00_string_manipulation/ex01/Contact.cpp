#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

//first_name, last_name, nickname, phone_number, darkest_secret
Contact::Contact(std::string c_first_name, std::string c_last_name,
	std::string c_nickname, std::string c_phone_number,
	std::string c_darkest_secret)
{
	this->first_name = c_first_name;
	this->last_name = c_last_name;
	this->nickname = c_nickname;
	this->phone_number = c_phone_number;
	this->darkest_secret = c_darkest_secret;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getname(void)
{
	return (this->first_name);
}

std::string Contact::getlast_name(void)
{
	return (this->last_name);
}

std::string Contact::getphone_number(void)
{
	return (this->phone_number);
}

std::string Contact::getnickname(void)
{
	return (this->nickname);
}

std::string Contact::getsecret(void)
{
	return (this->darkest_secret);
}