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

void	PmergeMe::mergeInsertSort(void)
{
	size_t size = vect.size();
	int pairs = size / 2;
	int odd = size % 2;
	vectTree extra;

	if (odd)
	{
		extra = vectTree(vect.back());
		/* temp steps */
		vect.pop_back();
		pend.push_back(extra);
	}
	// sort 3 or rather sort final 2 for now
	if (pairs < 2)
	{
		
		// when the size is 3 or less
		// sort  the max value of each tree branch
		// if size - odd is more than 1 
		// ie: size 2 odd 0, size 3 odd 1
		// if 2nd is smaller than 1st, swap
		if (size - odd > 1 && vect[1].max < vect[0].max)
			std::swap(vect[0], vect[1]);

		// if size 3 odd 1  do not include size 1 odd 1
		// if 3rd is smaller than 2nd, swap
		// if (odd  && vect[2].max < vect[1].max) 
		if (odd && vect[2].max < vect[1].max) 
		{
			std::swap(vect[2], vect[1]);

			if (vect[1].max < vect[0].max) 
				std::swap(vect[0], vect[1]);
		}
		return;
	}
	else
	{
		for (int i = 0; i < pairs; i++)
		{
			// vect[i] = vectTree(vect[i], vect[size - 1 - i]);
			vect[i] = vectTree(vect[i], vect[pairs + i]);
		}
		for (int i = 0; i < pairs; i++)
		{
			vect.pop_back();
		}
		printVectTree(vect, 0);
		this->mergeInsertSort();
	}
}

vectTree::vectTree(vectTree const &a, vectTree const &b) 
{
	if (a.max < b.max) {
		max = b.max;
		arr = b.arr;
		arr.push_back(a);
	} else {
		max = a.max;
		arr = a.arr;
		arr.push_back(b);
	}
}

void	PmergeMe::doVect(void)
{
	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		vect.push_back(vectTree(*it));
	printVectTree(vect, 0);
	mergeInsertSort();
	printVectTree(vect, 0);
	printVectTree(pend, 0);
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


vectTree &vectTree::operator=(vectTree const &other)
{
	max = other.max;
	arr = other.arr;
	return (*this);
}

vectTree::vectTree(vectTree const &other)
{
	max = other.max;
	arr = other.arr;
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
