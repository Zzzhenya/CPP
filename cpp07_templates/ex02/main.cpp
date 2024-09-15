#include <iostream>
#include "Array.hpp"

int main(void)
{
	{
		const unsigned int len = 4;
		Array<int> arr = Array<int>(len);
		for (unsigned int i = 0; i < len; i++)
		{
			if (i == len - 1)
				std::cout << arr._arr[i] << std::endl;
			else
				std::cout << arr._arr[i] << " ";
		}
	}
	{
		const unsigned int len = 0;
		Array<int> arr = Array<int>(len);
		for (unsigned int i = 0; i < len; i++)
		{
			if (i == len - 1)
				std::cout << arr._arr[i] << std::endl;
			else
				std::cout << arr._arr[i] << " ";
		}
	}
	{
		// copy constructor - heap
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> *arr1 = new Array<int>(len1);
		Array<int> *arr2 = new Array<int>(len2);
		std::cout << "arr1: " << arr1->_n << std::endl;
		std::cout << "arr2: " << arr2->_n << std::endl;
		arr2 = new Array<int>(*arr1);
		std::cout << "arr1: " << arr1->_n << std::endl;
		std::cout << "arr2: " << arr2->_n << std::endl;
		delete arr1; delete arr2;

	}
	{
		// copy constructor - stack
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> arr1 = Array<int>(len1);
		Array<int> arr2 = Array<int>(len2);
		std::cout << "arr1: " << arr1._n << std::endl;
		std::cout << "arr2: " << arr2._n << std::endl;
		arr2 = Array<int>(arr1);
		std::cout << "arr1: " << arr1._n << std::endl;
		std::cout << "arr2: " << arr2._n << std::endl;
	}
	{
		// copy assignment overload - stack
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> arr1 = Array<int>(len1);
		Array<int> arr2 = Array<int>(len2);
		std::cout << "arr1: " << arr1._n << std::endl;
		std::cout << "arr2: " << arr2._n << std::endl;
		arr2 = arr1;
		std::cout << "arr1: " << arr1._n << std::endl;
		std::cout << "arr2: " << arr2._n << std::endl;
	}
	{
		// copy assignment overload - heap
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> *arr1 = new Array<int>(len1);
		Array<int> *arr2 = new Array<int>(len2);
		std::cout << "arr1: " << arr1->_n << std::endl;
		std::cout << "arr2: " << arr2->_n << std::endl;
		*arr2 = *arr1;
		std::cout << "arr1: " << arr1->_n << std::endl;
		std::cout << "arr2: " << arr2->_n << std::endl;
		delete arr1; delete arr2;

	}
	// Array<int>();
	return (0);
}
