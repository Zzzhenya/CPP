#include "PmergeMe.hpp"

int jcobsthalSeries(int n)
{
	static std::vector<int> series;
	if (series.empty())
	{
		series.push_back(0);
		series.push_back(1);
	}
	if (n < 0)
	{
		// for (std::vector<int>::const_iterator i = series.begin();
		// 	i != series.end(); i++)
		// 	std::cout << *i << " ";
		// std::cout << std::endl;
		series.clear();
		return (-1);
	}
	for (int i = 2; i <= n; i++)
	{
		if (series.size() <= (size_t)i)
		{
			int temp = (series[i - 1]) + 2 * (series[i - 2]);
			series.push_back(temp);
		}
	}
	return (series[n]);
}

int startAtThree(int i)
{
	return (jcobsthalSeries(i + 3));
}

PmergeMe::PmergeMe(void)
{
	comparisons = 0;
	reset();
	inSeries.clear();
}

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

/*
	insert from pend to vect(main)
	first the first element from pend -> b1 -> idx 0 (Jacobsthal 1) no 1
	then Jacobsthal number's -> starting from 3 -> idx 2 no 3
	then in reverse until previous jacobsthal that is 3 to 1 -> only 2 here
	then Jacobsthal number 5 -> idx 4 no 5
	then in reverse until previous jacobsthal that is 5 to 3 -> only 4 here
	then Jacobsthal number 11 -> idx 10 no 11
	then in reverse until previous jacobsthal that is 11 to 5 -> no 10, 9, 8, 7, 6 here
	
	if pend has less number of elements than jacobsthal number, 
	add them in reverse order from the last element

	clear the pend after each iteration
*/

void vectInsertion(std::vector<vectTree> &pend,std::vector<vectTree> &vect, int &comparisons)
{
	size_t 	subSeriesStart = 0;
	size_t 	currALoc = 0;
	int 	jcobNum = 0;

	while (subSeriesStart < pend.size()){
		size_t	idx = startAtThree(jcobNum) - 1;
		if (idx >= pend.size()) { idx = pend.size() - 1; }
		currALoc = subSeriesStart + idx + 1;
		while (idx > subSeriesStart) {
			
			std::vector<vectTree>::iterator it = std::upper_bound(
				vect.begin(), vect.begin() + currALoc, pend[idx]);
			comparisons += std::distance(vect.begin(), it);
			vect.insert(it,pend[idx]);
			--idx;
		}
		subSeriesStart = startAtThree(jcobNum++) - 1;
	}
	pend.clear();
}

/*
	if a series of size 1 return
		exit condition 1 : only 1 numberv

	sort 2 and sort 3 : sort the max value of each tree branch in ascending order
		for both size 2 and 3 if 2nd is smaller than 1st, swap
		for size 3 if 3rd is smaller than 2nd, swap
			for size 3 if 2nd is smaller than 1st, swap
		exit condition 2: only 2 or 3 numbers in the series ( originally or by merging)

	merge and make pairs
	recurse()

	generate the pend and main, vect is main now
		also you remove the last element from vect.arr and add to pend
			which is the b1; max + first element is a1
			pend only has b's and main only has a's(part with max)
		add the straggler/odd fella to the end of pend which is considered a "b"

	start insert
		insert the first element from pend to the front of main (b1, b1 is always less than a1)

	we don't change the size of pend even when we insert to main, 
	because we need to keep track of the index

*/

void	PmergeMe::mergeInsertSort(void)
{
	size_t size = vect.size();
	int pairs = size / 2;
	int odd = size % 2;
	vectTree extra;


	if (!pairs)
		return;

	if (odd)
		extra = vectTree(vect.back());

	if (pairs < 2)
	{
		if (size - odd > 1 && vect[1] < vect[0])
			std::swap(vect[0], vect[1]);
		comparisons++;
		if ( odd && vect[2] < vect[1]) 
		{
			std::swap(vect[2], vect[1]);
			if (vect[1] < vect[0]) 
				std::swap(vect[0], vect[1]);
			comparisons++;
		}
		comparisons++;
		return;
	}
	std::vector<vectTree> temp;
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		temp.push_back(vectTree(vect[i], vect[i + 1]));
		comparisons++;
	}
	vect = temp;
	// printVectTree(vect, 0);
	this->mergeInsertSort(); 
 
	for ( std::vector<vectTree>::iterator it = vect.begin();
		it != vect.end();
		it++) 
	{
		pend.push_back(it->arr.back());
		it->arr.pop_back();
	}
	if (odd)
		pend.push_back(extra);

	vect.insert(vect.begin(), pend.front());

	vectInsertion(pend, vect, comparisons);
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

void	PmergeMe::reset(void)
{
	jcobsthalSeries(-1);
	comparisons = 0;
	vect.clear();
	pend.clear();
}

void	PmergeMe::doVect(void)
{
	bool Error = false;
	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		vect.push_back(vectTree(*it));
	std::cout << "before:\t\t";
	printVectTree(vect, 0);
	mergeInsertSort();
	for (std::vector<vectTree>::const_iterator it = vect.begin(); it + 1 != vect.end(); it++)
	{
		if (*(it + 1) < *it)
		{
			Error = true;
			break;
		}
	}
	if (Error)
		std::cerr << "Not sorted\n";
	else
	{
		std::cout << "after :\t\t";
		printVectTree(vect, 0);
	}
	reset();
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


bool vectTree::operator<(vectTree const &other) const
{
	if (this->max < other.max)
		return (true);
	return (false);
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
