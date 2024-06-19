#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address of brain: ";
	std::cout << &brain << std::endl;
	std::cout << "Memory address of stringPTR: ";
	std::cout << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: ";
	std::cout << &stringREF << std::endl;
	return (0);
}