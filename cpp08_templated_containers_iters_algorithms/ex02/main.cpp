#include <stack>
#include <iostream>
#include "MutantStack.hpp"

int main(void)
{
	std::stack<int> stk;

	MutantStack<int> mtstk;

	mtstk.push(4);
	mtstk.push(3);
	stk.push(4);
	stk.push(3);
	
	// for (std::stack<int>::iterator it = stk.begin(); it != stk.end(); it++)
	// 	std::cout << *it << std::endl;
	for (MutantStack<int>::iterator it = mtstk.begin(); it != mtstk.end(); it++)
		std::cout << *it << std::endl;

	return (0);
}
