#include <iostream>
#include "PmergeMe.hpp"
#include <vector>
#include <string>


/*
Argument: 	positive integer sequence
Use: 		merge-insert sort algorithm
Use: 		two different STL
With: 		Ford-Johnson algorithm
Implement: 	algorithm for each container
Handle: 	at least 3000 different integers
Manage: 	Duplicates

Time taken by the algorithm = time for the sorting + time for the data management

If error: 	Error message on cerr

Output: on cout
	Line1: "explicit text" [unsorted positive integer sequence]
	Line2: "explicit text" [sorted positive integer sequence]
	Line3: [Time taken by the algorithm] [Container type]
	Line4: [Time taken by the algorithm] [Container type]
*/

static size_t	jacobsthal(unsigned int n)
{
	static std::vector<size_t>	jacobsthal_cache;

	if (n < jacobsthal_cache.size()) { return jacobsthal_cache[n]; }
	if (n < 2) {
		jacobsthal_cache.push_back(0);
		jacobsthal_cache.push_back(1);
		return (n == 1);
	}
	size_t const	res(2 * jacobsthal(n - 2) + jacobsthal(n - 1));
	jacobsthal_cache.push_back(res);
	// for (std::vector<size_t>::iterator it = jacobsthal_cache.begin(); it != jacobsthal_cache.end(); it++)
	// 	std::cout << *it << ' ';
	std::cout << "here: " << res << std::endl;
	return (jacobsthal_cache[n]);
}

static std::vector<size_t> jacobsthal_vect(unsigned int val)
{
	static std::vector<size_t>	jacobsthal_vect;

	for (size_t i = 0; i < val; i++)
        jacobsthal_vect.push_back(jacobsthal(i));

    return (jacobsthal_vect);
}

int main(int argc, char **argv)
{
	if (argc == 2 && std::atoi(argv[1]) > 0)
	{
		// size_t val = std::atoi(argv[1]);
		// for (size_t i = 0; i < val; i++)
        // 	std::cout << jacobsthal(i) << ' ';
		// std::cout << std::endl;
		std::vector<size_t> ret = jacobsthal_vect(std::atoi(argv[1]));
		if (ret.size() > 0)
		{
			for (std::vector<size_t>::iterator it = ret.begin(); it != ret.end(); it++)
				std::cout << *it << ' ';
			std::cout << std::endl;
		}
	}
	else
		return (1);


/*
	std::vector<std::string> a(3, "Hello World");
	std::vector<std::string> b;
	std::vector<std::string> c;
	std::cout << "a: " << std::endl;
	for (std::vector< std::string >::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
	// https://stackoverflow.com/questions/15975575/back-inserter-or-push-back
    // algo_func(src.begin(), src.end(), std::back_inserter(dest))
	std::copy(a.begin(), a.end(), std::back_inserter(c));

	std::cout << "c: "<< std::endl;
	for (std::vector< std::string >::iterator it = c.begin(); it != c.end(); it++)
        std::cout << *it << ' ';
	std::cout << std::endl;

	for (std::vector< std::string >::iterator it = a.begin(); it != a.end(); it++)
        b.push_back(*it);

	std::cout << "b: "<< std::endl;
	for (std::vector< std::string >::iterator it = b.begin(); it != b.end(); it++)
        std::cout << *it << ' ';
	std::cout << std::endl;
	//std::cout << "Hello World" << std::endl;*/
	return (0);
}
