#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <algorithm>

template <typename T>
void print_val(T &v, typename T::iterator &loc)
{
	if (loc != v.end())
		std::cout << "distance: " <<  distance(v.begin(),loc) << "\tval: " << *loc << std::endl;
	else
		std::cout << "distance: " <<  distance(v.begin(),loc) << "\treturned v.end()"  << std::endl;
}

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
	return (find(haystack.begin(), haystack.end(), needle));
}

#endif
