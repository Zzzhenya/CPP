#include <iostream>
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

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./pmergme < series of numbers >" << std::endl;
		return (1);
	}
	PmergeMe machine;
	for (int i = 1; i < argc; i++)
	{
		// check if string is a positive number and throw error
		machine.pushNum(std::atoi(argv[i]));
		// std::cout << argv[i] << std::endl;
	}
	machine.printSeries();

	return (0);
}
