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
				std::cout << arr[i] << std::endl;
			else
				std::cout << arr[i] << " ";
		}
	}
	{
		const unsigned int len = 0;
		Array<int> arr = Array<int>(len);
		for (unsigned int i = 0; i < len; i++)
		{
			if (i == len - 1)
				std::cout << arr[i] << std::endl;
			else
				std::cout << arr[i] << " ";
		}
	}
	{
		// copy constructor - heap
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> *arr1 = new Array<int>(len1);
		Array<int> *arr2 = new Array<int>(len2);
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		arr2 = new Array<int>(*arr1);
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		delete arr1; delete arr2;

	}
	{
		// copy constructor - stack
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> arr1 = Array<int>(len1);
		Array<int> arr2 = Array<int>(len2);
		std::cout << "arr1: " << arr1.size() << std::endl;
		std::cout << "arr2: " << arr2.size() << std::endl;
		arr2 = Array<int>(arr1);
		std::cout << "arr1: " << arr1.size() << std::endl;
		std::cout << "arr2: " << arr2.size() << std::endl;
	}
	{
		// copy assignment overload - stack
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> arr1 = Array<int>(len1);
		Array<int> arr2 = Array<int>(len2);
		std::cout << "arr1: " << arr1.size() << std::endl;
		std::cout << "arr2: " << arr2.size() << std::endl;
		arr2 = arr1;
		std::cout << "arr1: " << arr1.size() << std::endl;
		std::cout << "arr2: " << arr2.size() << std::endl;
	}
	{
		// copy assignment overload - heap
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> *arr1 = new Array<int>(len1);
		Array<int> *arr2 = new Array<int>(len2);
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		*arr2 = *arr1;
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		delete arr1; delete arr2;

	}
	{
		// subscript operator
		const unsigned int len = 4;
		Array<int> arr = Array<int>(len);
		for (unsigned int i = 0; i < len; i++)
		{
			if (i == len - 1)
				std::cout << arr[i] << std::endl;
			else
				std::cout << arr[i] << " ";
		}
		arr[0] = 12;
		arr[1] = 2;
		arr[2] = 0;
		arr[3] = 2290;
		for (unsigned int i = 0; i < len; i++)
		{
			if (i == len - 1)
				std::cout << arr[i] << std::endl;
			else
				std::cout << arr[i] << " ";
		}
	}
	{
		// subscript operator
		const unsigned int len = 4;
		Array<int> *arr = new Array<int>(len);
		for (unsigned int i = 0; i < len ; i++)
		{
			if (i == len - 1)
				std::cout << (*arr)[i] << std::endl;
			else
				std::cout << (*arr)[i] << " ";
		}
		delete arr;
	}
	{
		// checking the weird 3rd value at initiation
		int *arr = new int[12];
		for (int i = 0; i < 12; i++)
			std::cout << arr[i] << std::endl;
		delete [] arr;
	}

	{
		// subscript operator - out of range
		const unsigned int len = 4;
		Array<int> *arr = new Array<int>(len);
		try
		{
			for (unsigned int i = 0; i < len  + 1; i++)
			{
				if (i == len - 1)
					std::cout << (*arr)[i] << std::endl;
				else
					std::cout << (*arr)[i] << " ";
			}
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			
		}
		delete arr;
	}

	{
		// size
		const unsigned int len = 4;
		Array<int> *arr = new Array<int>(len);
		// arr->size() = 20;
		std::cout << arr->size() << std::endl;
		delete arr;
	}
	// Array<int>();
	return (0);
}
