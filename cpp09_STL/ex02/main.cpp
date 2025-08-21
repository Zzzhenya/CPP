#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include "PmergeMe.hpp"

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

int error(std::string str)
{
	std::cerr << str << std::endl;
	return (1);
}

int is_an_int(std::string str)
{
	try
	{
		size_t size = str.size();
		size_t i = 0;
		if (!std::isdigit(str[i]) && str[i] != '+')
			return (0);
		i++;
		while (i < size)
		{
			if (!std::isdigit(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	catch(const std::exception& e)
	{
		return (0);
	}
}

int	convert_to_int(char *str, int &val)
{
	try
	{
		val = std::atoi(str);
		if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
			return (1);
		return (0);
	}
	catch(std::exception &e)
	{
		return (0);
	}

}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./pmergme < series of numbers >" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe machine;
		for (int i = 1; i < argc; i++)
		{
			if (argv[i] == NULL || argv[i][0] == '\0')
				return (error("Error"));
			int val;
			if (!is_an_int(argv[i]))
				return (error("Error"));
			if (!convert_to_int(argv[i], val) || val < 0)
				return (error("Error"));
			machine.pushNum(val);
		}
		machine.doVect();
		machine.doList();
		// machine.vect.clear();
		// machine.list.clear();
		// machine.printSeries();
	}
	catch (std::exception &e)
	{
		return (error("Error"));
	}
	return (0);
}
