#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>

template <typename T>
int easyfind(T &haystack, int needle)
{
	try
	{
		for (unsigned long it = 0; it < haystack.size(); it++)
		{
			if (haystack[it] == needle)
				return ((int)it);
		}
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception ";
		std::cerr << e.what() << std::endl;
	}
	return (-1);
}

#endif
