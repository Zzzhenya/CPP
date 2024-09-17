#include <iostream>
#include <vector>
#include <limits>
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
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
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
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
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
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
		if (loc != 0)
			return (0);
	}
	{
		std::vector<int> v (0, 0);
		// for (int i = 0; i < (int)v.size(); i++)
		// {
		// 	v[i] = i + 2;
		// }
		int loc = ::easyfind(v, 5);
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
		if (loc != -1)
			return (0);
	}
	{
		std::vector<int> v;
		// for (int i = 0; i < (int)v.size(); i++)
		// {
		// 	v[i] = i + 2;
		// }
		int loc = ::easyfind(v, 5);
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
		if (loc != -1)
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = INT_MIN;
		}
		int loc = ::easyfind(v, INT_MIN);
		if (loc != -1)
			std::cout << "loc: "  << loc << "\t val: "<< v[loc] << std::endl;
		else
			std::cout << "loc: "  << loc << std::endl;
		if (loc != 0)
			return (0);
	}
	return (1);
}

#include <set>



int set_tests(void)
{
	std::cout  << "========= set tests =========" << std::endl;
	
	std::set<int> keys;
	keys.insert(3);
	// keys.insert(4);
	// std::cout << easyfind(keys, 3) << std::endl; 
	// std::cout << easyfind(keys, 4) << std::endl; 
	// std::cout << easyfind(keys, -2) << std::endl;
	std::set<int>::iterator ret = find(keys.begin(), keys.end(), 3);
	if (ret != keys.end())
		std::cout << *ret << std::endl;
	else
		std::cout << *ret << std::endl;


	return (1);
}

#include <algorithm>

int main(void)
{
	// std::vector<int> v (6, 0);
	// for (int i = 0; i < 7; i++)
	// {
	// 	v[i] = i + 2;
	// }
	// std::vector<int>::iterator ret = find(v.begin(), v.end(), 5);
	// if (ret != v.end())
	// 	std::cout << *ret << std::endl;

	// if (!vector_tests())
	// 	std::cout << "================================  ERROR" << std::endl;

	if (!set_tests())
		std::cout << "================================  ERROR" << std::endl;
	return (0);
}
