#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <vector>

class vectTree
{
public:
	vectTree();
	vectTree(int val);
	vectTree(int first, int second);
	vectTree(vectTree const &a, vectTree const &b);
	vectTree(vectTree const &other);
	vectTree &operator=(vectTree const &other);

	int 					max;
	std::vector<vectTree>	arr;

};

void printVectTree(std::vector<vectTree> tr, int level);

class PmergeMe
{
public:
	void	pushNum(int num);
	void	printSeries(void);
	void	doVect(void);
	void	mergeInsertSort(void);

	std::vector<int> inSeries;

	std::vector<vectTree>	vect;
	std::vector<vectTree>	pend;
};

int jcobsthalSeries(int n);
int startAtThree(int i);

#endif
