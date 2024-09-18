#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>
#include "easyfind.hpp"

// void print_val(std::vector<int> &v, std::vector<int>::iterator &loc)
// {
// 	if (loc != v.end())
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\tval: " << *loc << std::endl;
// 	else
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\treturned v.end()"  << std::endl;
// }

// void print_val_set(std::set<int> &v, std::set<int>::iterator &loc)
// {
// 	if (loc != v.end())
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\tval: " << *loc << std::endl;
// 	else
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\treturned v.end()"  << std::endl;
// }

// void print_val_multset(std::multiset<int> &v, std::multiset<int>::iterator &loc)
// {
// 	if (loc != v.end())
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\tval: " << *loc << std::endl;
// 	else
// 		std::cout << "distance: " <<  distance(v.begin(),loc) << "\treturned v.end()"  << std::endl;
// }

int vector_tests(void)
{
	std::cout  << "========= Vector tests =========" << std::endl;
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = i + 2;

		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if ( *loc != 5 || distance(v.begin(),loc) != 3)
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = 0;

		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = 5;

		std::vector<int>::iterator loc  = easyfind(v, 5);
		print_val(v, loc);
		if (*loc != 5 || distance(v.begin(),loc) != 0)
			return (0);
	}
	{
		std::vector<int> v (0, 0);
		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::vector<int> v;
		std::vector<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::vector<int> v (6, 0);
		for (int i = 0; i < 6; i++)
			v[i] = INT_MIN;
		std::vector<int>::iterator loc = easyfind(v, INT_MIN);
		print_val(v, loc);
		if (*loc != INT_MIN || distance(v.begin(),loc) != 0)
			return (0);
	}
	return (1);
}

int set_tests(void)
{
	std::cout  << "========= set tests =========" << std::endl;
	{
		std::set<int> keys;
		std::set<int>::iterator ret;

		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);

		keys.insert(3);
		keys.insert(4);

		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (*ret != 3 || distance(keys.begin(),ret) != 0)
			return (0);
		ret = easyfind(keys, 4);
		print_val(keys, ret);
		if (*ret != 4 || distance(keys.begin(),ret) != 1)
			return (0);
		ret = easyfind(keys, -2);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);
		keys.erase(3);
		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);
		ret = easyfind(keys, 4);
		print_val(keys, ret);
		if (*ret != 4 || distance(keys.begin(),ret) != 0)
			return (0);
	}
	return (1);
}

int multiset_tests(void)
{
	std::cout  << "========= set tests =========" << std::endl;
	{
		std::multiset<int> keys;
		std::multiset<int>::iterator ret;

		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);

		keys.insert(3);
		keys.insert(4);
		keys.insert(3);
		keys.insert(4);
		keys.insert(100); 

		// 3 , 3 , 4 , 4 , 100

		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (*ret != 3 || distance(keys.begin(),ret) != 0)
			return (0);

		ret = easyfind(keys, 4);
		print_val(keys, ret);
		if (*ret != 4 || distance(keys.begin(),ret) != 2)
			return (0);

		ret = easyfind(keys, -2);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);

		keys.erase(3); // deletes all 3's

		ret = easyfind(keys, 3);
		print_val(keys, ret);
		if (ret != keys.end() || distance(keys.begin(),ret) != (int)keys.size())
			return (0);

		ret = easyfind(keys, 4);
		print_val(keys, ret);
		if (*ret != 4 || distance(keys.begin(),ret) != 0)
			return (0);
	}
	return (1);
}

int main(void)
{

	if (!vector_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;
	
	if (!set_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;

	if (!multiset_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;
	return (0);
}
