#include <iostream>
#include <vector>
#include "easyfind.hpp"

int vector_tests(void)
{
	std::cout  << "========= Vector tests =========" << std::endl;
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = i + 2;
		}
		int loc = ::easyfind(v, 5);
		std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		if (loc != 3)
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = 0;
		}
		int loc = ::easyfind(v, 5);
		std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		if (loc != -1)
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = 5;
		}
		int loc = ::easyfind(v, 5);
		std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		if (loc != 0)
			return (0);
	}
	return (1);
}

int main(void)
{
	if (vector_tests())
		std::cout << "================================  OK" << std::endl;
	return (0);
}
