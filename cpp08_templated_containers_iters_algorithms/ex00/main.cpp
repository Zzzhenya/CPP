#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <limits>
#include <algorithm>
#include "easyfind.hpp"

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
			v[i] = std::numeric_limits<int>::max();
			//v[i] = INT_MIN;
		std::vector<int>::iterator loc = easyfind(v, std::numeric_limits<int>::min());
		//std::vector<int>::iterator loc = easyfind(v, INT_MIN);
		print_val(v, loc);
		// if (*loc != INT_MIN || distance(v.begin(),loc) != 0)
		if (*loc != std::numeric_limits<int>::min() || distance(v.begin(),loc) != 0)
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

int deque_tests(void)
{
	std::cout  << "========= Deque tests =========" << std::endl;
	{
		std::deque<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = i + 2;

		std::deque<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if ( *loc != 5 || distance(v.begin(),loc) != 3)
			return (0);
	}
	{
		std::deque<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = 0;

		std::deque<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::deque<int> v (6, 0);
		for (int i = 0; i < (int)v.size(); i++)
			v[i] = 5;

		std::deque<int>::iterator loc  = easyfind(v, 5);
		print_val(v, loc);
		if (*loc != 5 || distance(v.begin(),loc) != 0)
			return (0);
	}
	{
		std::deque<int> v (0, 0);
		std::deque<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::deque<int> v;
		std::deque<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::deque<int> v (6, 0);
		for (int i = 0; i < 6; i++)
			v[i] = std::numeric_limits<int>::min();
			//v[i] = INT_MIN;
		// std::deque<int>::iterator loc = easyfind(v, INT_MIN);
		std::deque<int>::iterator loc = easyfind(v, std::numeric_limits<int>::min());
		print_val(v, loc);
		//if (*loc != INT_MIN || distance(v.begin(),loc) != 0)
		if (*loc != std::numeric_limits<int>::min() || distance(v.begin(),loc) != 0)
			return (0);
	}
	return (1);
}

int list_tests(void)
{
	std::cout  << "========= List tests =========" << std::endl;
	{
		std::list<int> v;
		for (int i = 0; i < 6; i++)
			v.push_back(i + 2);

		std::list<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if ( *loc != 5 || distance(v.begin(),loc) != 3)
			return (0);
	}
	{
		std::list<int> v;
		for (int i = 0; i < 6; i++)
			v.push_back(0);

		std::list<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::list<int> v;
		for (int i = 0; i < 6; i++)
			v.push_back(5);

		std::list<int>::iterator loc  = easyfind(v, 5);
		print_val(v, loc);
		if (*loc != 5 || distance(v.begin(),loc) != 0)
			return (0);
	}
	{
		std::list<int> v;
		std::list<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::list<int> v;
		std::list<int>::iterator loc = easyfind(v, 5);
		print_val(v, loc);
		if (loc != v.end() || distance(v.begin(),loc) != (int)v.size())
			return (0);
	}
	{
		std::list<int> v;
		for (int i = 0; i < 6; i++)
			v.push_back(std::numeric_limits<int>::min());
		//v.push_back(INT_MIN);
		//std::list<int>::iterator loc = easyfind(v, INT_MIN);
		std::list<int>::iterator loc = easyfind(v, std::numeric_limits<int>::min());
		print_val(v, loc);
		//if (*loc != INT_MIN || distance(v.begin(),loc) != 0)
		if (*loc != std::numeric_limits<int>::min() || distance(v.begin(),loc) != 0)
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

	if (!deque_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;

	if (!list_tests())
		std::cout << "================================  ERROR" << std::endl;
	else
		std::cout << "================================  OK" << std::endl;

	// if (!set_tests())
	// 	std::cout << "================================  ERROR" << std::endl;
	// else
	// 	std::cout << "================================  OK" << std::endl;

	// if (!multiset_tests())
	// 	std::cout << "================================  ERROR" << std::endl;
	// else
	// 	std::cout << "================================  OK" << std::endl;
	
	return (0);
}
