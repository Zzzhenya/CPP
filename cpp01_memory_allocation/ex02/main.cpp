#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address of brain: \t";
	std::cout << &brain << std::endl;
	std::cout << "Memory address of stringPTR: \t";
	std::cout << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: \t";
	std::cout << &stringREF << std::endl;

	// values
	std::cout << "Value of brain: \t\t";
	std::cout << brain << std::endl;
	std::cout << "Value of stringPTR: \t\t";
	std::cout << *stringPTR << std::endl;
	std::cout << "Value of stringREF: \t\t";
	std::cout << stringREF << std::endl;

	return (0);
}