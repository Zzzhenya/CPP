#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include "easyfind.hpp"

void print_val(std::vector<int> &v, std::vector<int>::iterator &loc)
{
	if (loc != v.end())
		std::cout << "val: " << *loc << std::endl;
	else
		std::cout << "returned v.end()."  << std::endl;
}

void print_val_set(std::set<int> &v, std::set<int>::iterator &loc)
{
	if (loc != v.end())
		std::cout << "val: " << *loc << std::endl;
	else
		std::cout << "returned v.end()."  << std::endl;
}

int vector_tests(void)
{
	std::cout  << "========= Vector tests =========" << std::endl;
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
			v[i] = i + 2;

		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (*loc != 5)
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
			v[i] = 0;
		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end())
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = 5;
		}
		std::vector<int>::iterator loc  = easyfind(v, 5);
		print_val(v, loc);
		if (*loc != 5)
			return (0);
	}
	{
		std::vector<int> v (0, 0);
		// for (int i = 0; i < (int)v.size(); i++)
		// {
		// 	v[i] = i + 2;
		// }
		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end())
			return (0);
	}
	{
		std::vector<int> v;
		// for (int i = 0; i < (int)v.size(); i++)
		// {
		// 	v[i] = i + 2;
		// }
		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end())
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
		{
			v[i] = INT_MIN;
		}
		std::vector<int>::iterator loc = easyfind(v, INT_MIN);
		print_val(v, loc);
		if (*loc != INT_MIN)
			return (0);
	}
	return (1);
}

int set_tests(void)
{
	std::cout  << "========= set tests =========" << std::endl;
	{
		std::set<int> keys;
		keys.insert(3);
		keys.insert(4);

		std::set<int>::iterator ret = easyfind(keys, 3);
		print_val_set(keys, ret);
		if (*ret != 3)
			return (0);
		ret = easyfind(keys, 4);
		print_val_set(keys, ret);
		if (*ret != 4)
			return (0);
		ret = easyfind(keys, -2);
		print_val_set(keys, ret);
		if (ret != keys.end())
			return (0);
	}

	// std::cout << keys[1] << std::endl;

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

	if (!vector_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;

	if (!set_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;
	return (0);
}
