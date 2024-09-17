#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>

template <typename T>
int easyfind(T &haystack, int needle)
{
	int i = 0;
	try
	{
		for (typename T::iterator it = haystack.begin(); it != haystack.end(); it++)
		{
			if (*it == needle)
				return (i);
			i++;
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
