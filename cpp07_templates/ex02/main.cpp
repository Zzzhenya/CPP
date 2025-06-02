/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:57:38 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/27 20:49:47 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
void print_arr(Array<T> &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i  + 1 < size)
			std::cout << arr[i] << "\t";
		else
			std::cout << arr[i] << std::endl;
	}
}

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
		Array<int> *arr = new Array<int>(4);

		std::cout << arr->size() << std::endl;
		delete arr;
	}
	{
		Array<int> *arr = new Array<int>();

		std::cout << arr->size() << std::endl;
		delete arr;
	}
	{
		Array<int> *arr1 = new Array<int>();
		Array<int> *arr2 = new Array<int>();

		std::cout << arr1->size() << std::endl;
		std::cout << arr2->size() << std::endl;
		Array<int> arr3= Array<int>(*arr1);
		std::cout << arr3.size() << std::endl;
		delete arr1;
		delete arr2;	
	}
	{
		// copy constructor - heap
		const unsigned int len1 = 3;
		const unsigned int len2 = 10;
		Array<int> *arr1 = new Array<int>(len1);
		Array<int> *arr2 = new Array<int>(len2);
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		delete arr2;
		arr2 = new Array<int>(*arr1);
		std::cout << "arr1: " << arr1->size() << std::endl;
		std::cout << "arr2: " << arr2->size() << std::endl;
		delete arr1; delete arr2; 

	}
	{
		// copy constructor and assignment operator - stack
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
			arr[i] = 0;
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
	{
		int size = 10;
		Array<int> arr = Array<int>(10);
		int num[10] = {1, 22, 88, 33, 52, 42, 343, 23, 1223214, 1};
		for (int i =0; i < size; i++)
		{
			arr[size - i - 1] = num[i]; 
		}
		for (int i = 0; i < size; i++)
		{
			if (i  + 1 < size)
				std::cout << num[i] << "\t";
			else
				std::cout << num[i] << std::endl;
		}
		print_arr(arr, size);
		Array<int> *cpy = new Array<int>(arr);
		print_arr(arr, size);
		try
		{
			std::cout << arr[size+1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << arr[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete cpy;
		Array<std::string> str = Array<std::string>(4);
		for (int i = 3; i > 2; i --)
			str[i] = std::string("ABC");
		print_arr(str, 4);

	}
	return (0);
}
