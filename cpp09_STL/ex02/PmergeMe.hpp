#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <vector>
# include <time.h>
# include <sstream>
# include <iomanip>
# include <list>
# include <cstdlib>
# include <algorithm>

class listTree
{
public:
	listTree(void);
	listTree(int val);

	listTree(listTree const &a, listTree const &b);
	bool operator<(listTree const &other) const;
	listTree &operator=(listTree const &other);

	int 					max;
	std::list<listTree>		arr;
};

void printListTree(std::list<listTree> tr, int level);

class vectTree
{
public:
	vectTree();
	vectTree(int val);
	// vectTree(int first, int second);
	vectTree(vectTree const &a, vectTree const &b);
	vectTree(vectTree const &other);
	vectTree &operator=(vectTree const &other);
	bool operator<(vectTree const &other) const;

	int 					max;
	std::vector<vectTree>	arr;

};

void printVectTree(std::vector<vectTree> tr, int level);

class PmergeMe
{
public:
	PmergeMe(void);
	~PmergeMe(void);
	void	pushNum(int num);
	void	printSeries(void);
	void	reset(void);

	void	doVect(void);
	void	mergeInsertSortVect(void);

	void	doList(void);
	void	mergeInsertSortList(void);
	void 	binaryInsertionSort(size_t sort_end, listTree &insertVal);

	std::vector<int> 		inSeries;

	std::vector<vectTree>	vect;
	std::vector<vectTree>	pend;

	std::list<listTree>	list;
	std::list<listTree>	lpend;

	int 					comparisons;
};

int jcobsthalSeries(int n);
int startAtThree(int i);

#endif
