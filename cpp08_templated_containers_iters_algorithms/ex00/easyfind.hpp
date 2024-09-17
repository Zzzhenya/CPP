#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
	for (typename T::iterator it = haystack.begin(); it != haystack.end(); it++)
	{
		if (*it == needle)
			return (it);
	}
	return (haystack.end());
}

#endif
