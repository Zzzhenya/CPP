/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:10:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/15 00:12:27 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Test
{
	public:
		Test(void): _a(1){};
		Test(int a): _a(a){};

		int _a;
};

std::ostream& operator<<(std::ostream& streamRef,const Test& obj)
{
	streamRef << obj._a;
	return (streamRef);
}


void	int_arr(void)
{
	std::cout << "\t\tInt array: stack\n";
	{
		int arr[3] = {9, 2, 3};
		std::cout << "\tarray:\n";
		::iter<int>(arr, 3, ::print<int>);
		std::cout << "\tmultiplying by 4...\n";
		::iter<int>(arr, 3, ::mult<int, 4>);
		std::cout << "\tarray:\n";
		::iter<int>(arr, 3, ::print<int>);	
	}
	std::cout << "\t\tInt array: heap\n";
	{
		int size = 10;
		int *arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 2 * i;
		std::cout << "\tarray:\n";
		::iter<int>(arr, size, ::print<int>);
		std::cout << "\tmultiplying by 4...\n";
		::iter<int>(arr, size, ::mult<int, 4>);
		std::cout << "\tarray:\n";
		::iter<int>(arr, size, ::print<int>);
		delete []arr;
	}
	std::cout << "\t\tInt array: NULL\n";
	{
		int *arr = NULL;
		std::cout << "\tarray:\n";
		::iter<int>(arr, 2, ::print<int>);
		std::cout << "\tmultiplying by 4...\n";
		::iter<int>(arr, 2, ::mult<int, 4>);
		std::cout << "\tarray:\n";
		::iter<int>(arr, 2, ::print<int>);
	}
	std::cout << "\t\tInt array: without values\n";
	{
		int size = 3;
		int *arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			if (i>size)
				arr[i] = 2 * i;
		}
		std::cout << "\tarray:\n";
		::iter<int>(arr, size, ::print<int>);
		std::cout << "\tmultiplying by 4...\n";
		::iter<int>(arr, size, ::mult<int, 4>);
		std::cout << "\tarray:\n";
		::iter<int>(arr, size, ::print<int>);
		delete []arr;
	}
}

void other_arrs(void)
{
	std::cout << "\t\tInt array: stack\n";
	{
		int arr[3] = {9, 2, 3};
		std::cout << "\tarray:\n";
		::iter<int>(arr, 3, ::print<int>);
	}
	std::cout << "\t\tDouble array: stack\n";
	{
		double arr[3] = {9.2, 2.7, 3.8};
		std::cout << "\tarray:\n";
		::iter<double>(arr, 3, ::print<double>);
		// ::iter<double>(arr, 3, ::mult<double, 4>);
	}
	std::cout << "\t\tLong array: stack\n";
	{
		long arr[3] = {90, 27, 38};
		std::cout << "\tarray:\n";
		::iter<long>(arr, 3, ::print<long>);
		::iter<long>(arr, 3, ::mult<long, 10>);
		std::cout << "\tarray:\n";
		::iter<long>(arr, 3, ::print<long>);
	}
	std::cout << "\t\tStd::string array: stack\n";
	{
		std::string arr[3] = {"Hello", "World", "!"};
		std::cout << "\tarray:\n";
		::iter<std::string>(arr, 3, ::print<std::string>);
		//::iter<std::string>(arr, 3, ::mult<std::string, 4>);
	}
	{
		Test arr[3] = {Test(3), Test(4), Test(10)};
		std::cout << "\tarray:\n";
		::iter<Test>(arr, 3, ::print<Test>);
		//::iter<Test>(arr, 3, ::mult<Test, Test(10)>);
	}
}


int main (void)
{
	int_arr();
	other_arrs();
	return 0;
}
