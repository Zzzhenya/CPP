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

	int 					max;
	std::vector<vectTree>	arr;

};

void printVectTree(std::vector<vectTree> tr, int level);

class PmergeMe
{
public:
	void pushNum(int num);
	void printSeries(void);
	void doVect();

	std::vector<int> inSeries;

	std::vector<vectTree>	vect;
};

#endif
