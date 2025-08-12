#include "PmergeMe.hpp"


void PmergeMe::pushNum(int num)
{
	inSeries.push_back(num);
}

void PmergeMe::printSeries(void)
{
	for (std::vector<int>::const_iterator it = inSeries.begin();
			it != inSeries.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != inSeries.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::doVect(void)
{
	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		vect.push_back(vectTree(*it));

	printVectTree(vect, 0);
}

vectTree::vectTree(void)
{
	max = -1;
}

vectTree::vectTree(int val)
{
	max = val;
}

vectTree::vectTree(int first, int second)
{
	if (first > second)
	{
		max = first;
		arr.push_back(vectTree(second));
	}
	else
	{
		max = second;
		arr.push_back(vectTree(first));
	}
}

void printVectTree(std::vector<vectTree> tr, int level)
{
	if (tr.size() == 0)
		return;
	std::vector<vectTree>::const_iterator it;
	if (level > 0)
		std::cout << "{ ";
	for (it = tr.begin(); it != tr.end(); it++)
	{
		std::cout  << it->max << " ";
		printVectTree(it->arr, level + 1);
		if (it + 1 == tr.end())
		{
			if (level > 0)
				std::cout << "} ";
			else
				std::cout << std::endl;
		}
	}
}
