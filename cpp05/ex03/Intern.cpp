#include "Intern.hpp"

Intern::Intern(void)
{
	debug(std::cout << "Intern default constructor\n");
}
Intern::~Intern(void)
{
	debug(std::cout << "Intern destructor\n");
}

// int getindex(std::string arr[3], std::string &name)
// {
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (arr[i] == name)
// 			return (i);
// 	}
// 	return (3);
// }

int getindex(std::string arr[3][6], std::string &name)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j=0; j < 6; j++)
		{
			if (arr[i][j] == name)
				return (i);
		}
	}
	return (3);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	//std::string arr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	std::string arr[3][6] = {
		{"ShrubberyCreationForm","Shrubbery","shrubbery", "shrubbery creation", "Shrubbery Creation", "Shrubbery creation"}
		,{"RobotomyRequestForm", "Robotomy", "robotomy", "robotomy request", "Robotomy Request", "Robotomy request"}
		, {"PresidentialPardonForm", "Presidential", "presidential", "presidential pardon", "Presidential Pardon", "Presidential pardon"}};
	switch(getindex(arr, name))
	{
		case (0):
			std::cout << "Intern creates " << arr[0][0] << std::endl;
			return (new ShrubberyCreationForm(target));
		case (1):
			std::cout << "Intern creates " << arr[1][0] << std::endl;
			return (new RobotomyRequestForm(target));
		case(2):
			std::cout << "Intern creates " << arr[2][0] << std::endl;
			return (new PresidentialPardonForm(target));
		case(3):
			std::cout << name << " does not exist\n";
	}
	return (NULL);
}