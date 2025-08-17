#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <vector>
# include <time.h>
# include <sstream>
# include <iomanip>

class vectTree
{
public:
	vectTree();
	vectTree(int val);
	vectTree(int first, int second);
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
	void	pushNum(int num);
	void	printSeries(void);
	void	doVect(void);
	void	mergeInsertSort(void);

	void	reset(void);

	std::vector<int> 		inSeries;

	std::vector<vectTree>	vect;
	std::vector<vectTree>	pend;

	int 					comparisons;
};

int jcobsthalSeries(int n);
int startAtThree(int i);

#endif
