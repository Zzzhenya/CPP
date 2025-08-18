#include "PmergeMe.hpp"

// Jacobsthal Series

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

// Jacobsthal Series - wrapper function

int startAtThree(int i)
{
	return (jcobsthalSeries(i + 3));
}

// Class PmergeMe functions

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

void	PmergeMe::mergeInsertSortVect(void)
{
	size_t size = vect.size();
	int pairs = size / 2;
	int odd = size % 2;
	vectTree extra;


	if (!pairs)
		return;

	if (odd)
	{
		extra = vectTree(vect.back());
		// vect.pop_back();
	}

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
	// printVectTree(vect, 0);
	std::vector<vectTree> temp;
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		temp.push_back(vectTree(vect[i], vect[i + 1]));
		comparisons++;
	}

	vect = temp;
	// printVectTree(vect, 0);
	this->mergeInsertSortVect(); 
 
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

void 	PmergeMe::binaryInsertionSort(size_t sort_end, listTree &insertVal)
{
	// std::cout << "BI: " << insertVal.max  << " sort end idx: " << sort_end << std::endl;
	// std::cout << "BI: " << std::endl;
	// printListTree(list, 0);

	size_t start = 0;
	size_t oldmid = 0;
	size_t mid = 0;

	std::list<listTree>::iterator it = list.begin();
	while (start < sort_end)
	{
		oldmid = mid;
		mid = start + ((sort_end - start)/2);
		std::advance(it, mid - oldmid);
		comparisons++;
		if (*it < insertVal)
			start = mid + 1;
		else
		{
			if (mid == start)
			{
				list.insert(it, insertVal);
				return;
			}
			sort_end = mid - 1;
		}	
	}
	it = list.begin();
	std::advance(it, start);
	// if start is before the list.end() and value at start is less than the insertVallue advance 1
	// else do not advance and insert at start
	//if (start < sort_end && *it < insertVal) 
	// std::cout << "start: " << start << std::endl;
	
	if (start < list.size() && *it < insertVal) 
		std::advance(it, 1);
	// else
	// 	std::cout << "this opetion\n";
	comparisons++;
	list.insert(it, insertVal);
}

void	PmergeMe::mergeInsertSortList(void)
{
	size_t		size = list.size();
	int			pairs = size / 2;
	int			odd = size % 2;
	listTree	extra;

	if (!pairs)
		return;

	if (odd)
	{
		extra = listTree(list.back());
		list.pop_back();
	}

	if (pairs < 2)
	{
		std::list<listTree>::iterator	first = list.begin();
		std::list<listTree>::iterator	second = list.begin();
		std::advance(second, 1);
		if ( size - odd > 1 && second->max < first->max) 
			list.splice(first, list, second);
		comparisons++;
		if ( odd && size == 3) 
		{
			// printListTree(list, 0);
			// list.pop_back();
			//binaryInsertionSort(1, *--list.end());
			binaryInsertionSort(1, extra);
		}	
		return;
	}
	// printListTree(list, 0);

	std::list<listTree> temp;
	std::list<listTree>::iterator p2 = list.begin();
	std::list<listTree>::iterator p1 = list.begin();
	std::advance(p2, 1);

	size_t i  = 0;
	while (i + 1 < size)
	{
		temp.push_back(listTree(*p1, *p2));
		std::advance(p1, 2);
		std::advance(p2, 2);
		i += 2;
		comparisons++;
	}

	list = temp;
	this->mergeInsertSortList();

	for ( std::list<listTree>::iterator it = list.begin();
		it != list.end();
		it++) 
	{
		lpend.push_back(it->arr.back());
		it->arr.pop_back();
	}
	if (odd)
		lpend.push_back(extra);

	list.insert(list.begin(), lpend.front());


	size_t 	subSeriesStart = 0;
	int 	jcobNum = 0;

	while (subSeriesStart < lpend.size()){
		size_t	idx = startAtThree(jcobNum) - 1;
		if (idx >= lpend.size())
			idx = lpend.size() - 1; 
		while (idx > subSeriesStart)
		{
			std::list<listTree>::iterator iter = lpend.begin();
			std::advance(iter, idx);
			binaryInsertionSort(list.size()-1 , *iter);
			--idx;
		}
		subSeriesStart = startAtThree(jcobNum++) - 1;
	}
	lpend.clear();
}


void	PmergeMe::reset(void)
{
	jcobsthalSeries(-1);
	comparisons = 0;
	// vect.clear();
	// list.clear();
	pend.clear();
	lpend.clear();
}

PmergeMe::~PmergeMe(void)
{
	reset();
	vect.clear();
	list.clear();
	inSeries.clear();
}

std::string processDuration(const struct timespec& begin, const struct timespec& end)
{
	std::stringstream os;

    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    long micro = (nanoseconds / 1000) + (seconds * 1000000);

    os << micro  << " us";
    return (os.str());
}

void	PmergeMe::doVect(void)
{
	struct timespec begin;
	struct timespec end;

	clock_gettime(CLOCK_REALTIME, &begin);
	bool Error = false;
	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		vect.push_back(vectTree(*it));
	std::cout << "before:\t\t";
	printVectTree(vect, 0);
	mergeInsertSortVect();
	clock_gettime(CLOCK_REALTIME, &end);

	for (std::vector<vectTree>::const_iterator it = vect.begin(); it + 1 != vect.end(); it++)
	{
		if (*(it + 1) < *it)
		{
			Error = true;
			break;
		}
	}
	std::cout << "after :\t\t";
	printVectTree(vect, 0);
	if (Error)
		std::cerr << "ERROR\tNot sorted\n";

	std::cout << "Time to process a range of " << inSeries.size();
	std::cout << " elements with std::vector : ";
	std::cout << processDuration(begin, end) << "\t";

	std::cout << "comparison: " << comparisons << std::endl;
	reset();

	// reset();
}

void	PmergeMe::doList(void)
{
	struct timespec begin;
	struct timespec end;

	bool Error = false;

	clock_gettime(CLOCK_REALTIME, &begin);

	std::vector<int>::const_iterator it = inSeries.begin();
	for (; it != inSeries.end(); it++)
		list.push_back(listTree(*it));

	mergeInsertSortList();

	clock_gettime(CLOCK_REALTIME, &end);

	// size_t i  = 0;
	std::list<listTree>::iterator iter = list.begin();
	for (std::vector<vectTree>::const_iterator it = vect.begin(); it!= vect.end(); it++)
	{
		if (it->max != iter->max)
		{
			Error = true;
			break;
		}
		std::advance(iter, 1);
	}

	// std::list<listTree>::iterator p2 = list.begin();
	// std::list<listTree>::iterator p1 = list.begin();
	// std::advance(p2, 1);

	// size_t i  = 0;
	// while (i + 2 < list.size())
	// {
	// 	std::advance(p1, 1);
	// 	std::advance(p2, 1);
	// 	if (*(p2) < *p1)
	// 	{
	// 		Error = true;
	// 		break;
	// 	}
	// 	i += 1;
	// }
	// printListTree(list, 0);
	if (Error)
		std::cerr << "ERROR\tNot sorted\n";

	// std::list<listTree> first;
	
	// first.push_back(listTree(33));
	// first.push_back(listTree(32));

	// std::list<listTree>::iterator i = list.begin();
	// i++;
	// i++;

	// first.splice(++first.begin(), list, i);



	std::cout << "Time to process a range of " << inSeries.size();
	std::cout << " elements with std::list : ";
	std::cout << processDuration(begin, end) << "\t";

	// std::cout << "list: ";
	// printListTree(list, 0);
	// std::cout << "first ";
	// printListTree(first, 0);

	std::cout << "comparison: " << comparisons << std::endl;

	std::cout << "after :\t\t";
	printListTree(list, 0);

	// std::cout << "list: ";
	// printListTree(list, 0);
	// std::cout << "pend: ";
	// printListTree(lpend, 0);
	// reset();

}

// Class listTree functions

listTree::listTree(void): max(-1)
{

}

listTree::listTree(int val): max(val)
{

}

bool listTree::operator<(listTree const &other) const
{
	if (this->max < other.max)
		return (true);
	return (false);
}

listTree::listTree(listTree const &a, listTree const &b)
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


// Class vectTree functions

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

vectTree::vectTree(void): max (-1)
{
}

vectTree::vectTree(int val): max (val)
{
}


// vectTree::vectTree(int first, int second)
// {
// 	if (first > second)
// 	{
// 		max = first;
// 		arr.push_back(vectTree(second));
// 	}
// 	else
// 	{
// 		max = second;
// 		arr.push_back(vectTree(first));
// 	}
// }

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

// extra functions for listTree
void printListTree(std::list<listTree> tr, int level)
{
	if (tr.size() == 0)
		return;
	std::list<listTree>::const_iterator it;
	if (level > 0)
		std::cout << "{ ";
	for (it = tr.begin(); it != tr.end(); it++)
	{
		std::list<listTree>::const_iterator temp = it;
		std::advance(temp, 1);
		if (level == 0 && temp == tr.end())
			std::cout  << it->max;
		else
			std::cout  << it->max << " ";
		printListTree(it->arr, level + 1);
		// std::list<listTree>::const_iterator temp = it;
		temp = it;
		std::advance(temp, 1);
		if (temp == tr.end())
		{
			if (level > 0)
				std::cout << "} ";
			else
				std::cout << std::endl;
		}
	}	
}

// extra functions for vectTree
void printVectTree(std::vector<vectTree> tr, int level)
{
	if (tr.size() == 0)
		return;
	std::vector<vectTree>::const_iterator it;
	if (level > 0)
		std::cout << "{ ";
	for (it = tr.begin(); it != tr.end(); it++)
	{
		if (level == 0 && it + 1 == tr.end())
			std::cout  << it->max;
		else
			std::cout  << it->max << " ";
		// std::cout  << it->max << " ";
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
