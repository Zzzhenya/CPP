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

	// if a series of  size 1 return - 
	if (!pairs) 
	{ 
		std::cout << "Here\n";
		return; 
	}
	if (odd)
	{
		extra = vectTree(vect.back());
		/* temp steps */
		// vect.pop_back();
		// pend.push_back(extra);
	}
	// sort 3 or rather sort final 2 for now
	// third value is the odd straggler, straggler is also added in the latter half of the 
	// algorithm and sorted at the end?
	if (pairs < 2)
	{
		
		// when the size is 3 or less
		// sort  the max value of each tree branch
		// if size - odd is more than 1 
		// ie: size 2 odd 0, size 3 odd 1
		// if 2nd is smaller than 1st, swap
		if (size - odd > 1 && vect[1].max < vect[0].max)
		{
			std::swap(vect[0], vect[1]);
		}
		comparisons++;

		// if size 3 odd 1  do not include size 1 odd 1
		// if 3rd is smaller than 2nd, swap
		// doesn't do anything now, straggler is not present in the vect temporirily
		// if (odd  && vect[2].max < vect[1].max) 
		if (odd && vect[2].max < vect[1].max) 
		{
			std::swap(vect[2], vect[1]);

			if (vect[1].max < vect[0].max) 
			{
				std::swap(vect[0], vect[1]);
			}
		}
		comparisons++;
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
	std::cout << "vect l1: ";
	printVectTree(vect, 0);
	this->mergeInsertSort(); 
	// generate the pend and main, vect is main now
	for (
		std::vector<vectTree>::iterator it = vect.begin();
		it != vect.end(); ++it) 
	{
		pend.push_back(it->arr.back());
		// also you remove the last element from vect.arr
		it->arr.pop_back();
	}
	std::cout << "vect l2: ";
	// add the straggler/odd fella to the pend
	if (odd)
		pend.push_back(extra);
	std::cout << "pend: ";
	printVectTree(pend, 0);

	// insert from pend to vect
	// first the first element from pend -> b1 -> idx 0 (Jacobsthal 1) no 1
	// then Jacobsthal number's -> starting from 3 -> idx 2 no 3
	// then in reverse until previous jacobsthal that is 3 to 1 -> only 2 here
	// then Jacobsthal number 5 -> idx 4 no 5
	// then in reverse until previous jacobsthal that is 5 to 3 -> only 4 here
	// then Jacobsthal number 11 -> idx 10 no 11
	// then in reverse until previous jacobsthal that is 11 to 5 -> no 10, 9, 8, 7, 6 here
	// if pend has less number of elements than jacobsthal number, 
	// add them in reverse order from the last element

	// 
	// std::vector<vectTree>	temp;
	// vect.reserve((pairs << 1) + odd);
	// only inseart the first element from pend to the front of temp
	vect.insert(vect.begin(), pend.front());
	// we don't change the size of pend even when we insert to main, 
	//because we need to keep track of the index
	size_t subSeriesStart = 0;
	size_t currALoc = 0;
	int jcobNum = 0;


	while (subSeriesStart < pend.size()){
		size_t	idx = startAtThree(jcobNum) - 1;
		// std::cout << "insert_mark J: " << idx + 1 << std::endl;
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


	std::cout << "temp: ";
	printVectTree(vect, 0);
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
	comparisons = 0;
	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		vect.push_back(vectTree(*it));
	printVectTree(vect, 0);
	mergeInsertSort();
	printVectTree(vect, 0);
	jcobsthalSeries(-1);
	// printVectTree(pend, 0);
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
