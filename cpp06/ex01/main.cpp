/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:31:04 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/12 21:26:28 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>
#include <sstream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data a = Data();
	Data *ptr = new Data(2);
	uintptr_t ret = 0;

	std::cout << "Data &a:\t" << &a << std::endl;
	std::cout << "Data *ptr:\t" << ptr << std::endl;
	std::cout << "uintptr_t ret:\t" << ret << std::endl;

	ptr->print_vals();
	a.print_vals();

	ret = Serializer::serialize(&a);

	std::cout << "Data &a:\t" << &a << std::endl;
	std::cout << "Data *ptr:\t" << ptr << std::endl;
	std::cout << "uintptr_t ret:\t" << ret << std::endl;

	delete ptr;

	ptr = Serializer::deserialize(ret);

	std::cout << "Data &a:\t" << &a << std::endl;
	std::cout << "Data *ptr:\t" << ptr << std::endl;
	std::cout << "uintptr_t ret:\t" << ret << std::endl;

	ptr->print_vals();
	a.print_vals();


	// try
	// {
	// 	int five = 5;
	// 	std::ostringstream os;
	// 	os << &five;
	// 	uintptr_t one = reinterpret_cast<uintptr_t>(&five);
	// 	int *ret = reinterpret_cast<int *>(one);
	// 	void *vret = reinterpret_cast<void *>(one);
	// 	char *abc = reinterpret_cast<char *>(one);
	// 	std::string *ab = reinterpret_cast<std::string *>(one);
	// 	float *a = reinterpret_cast<float *>(one);
	// 	double *b = reinterpret_cast<double *>(one);

	// 	std::cout << one << "\t" << sizeof(one) << std::endl;
	// 	std::cout << &five << "\t" << sizeof(&five) << std::endl;
	// 	std::cout << os.str() << "\t" << sizeof(os.str()) << std::endl;
	// 	std::cout << ret << "\t" << sizeof(ret) << std::endl;
	// 	std::cout << vret << "\t" << sizeof(vret) << std::endl;
	// 	std::cout << &abc << "\t" << sizeof(&abc) << std::endl;
	// 	std::cout << ab << "\t" << sizeof(ab) << std::endl;
	// 	std::cout << a << "\t" << sizeof(a) << std::endl;
	// 	std::cout << b << "\t" << sizeof(b) << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	
	return(0);
}
