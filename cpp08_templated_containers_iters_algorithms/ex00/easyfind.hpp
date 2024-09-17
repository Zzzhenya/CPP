#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
	return (find(haystack.begin(), haystack.end(), needle));
}

#endif
