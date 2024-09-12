/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:19:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/12 15:05:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int value_is_null(const char *ptr)
{
	if (!ptr)
		return (1);
	return (0);
}

void	run_converter(const char *ptr)
{
	if (value_is_null(ptr))
	{
		std::cout << "Value passed is a null pointer." << std::endl;
		return;
	}
	std::cout << ptr;
	const std::string		val = ptr;
	ScalarConverter::convert(val);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		run_converter(argv[1]);
	else
	{
		std::cout << "Usage: ./converter <value>" << std::endl;
		std::cout << "Usage(debug): ./dbg_converter <value>" << std::endl;
	}
// #ifdef _DEBUG
	{
		int a = 120;
		// char *val = NULL;
		// run_converter("A");
		// run_converter("");
		// run_converter(NULL);
		// run_converter(val);
		// run_converter("ABC");
		// run_converter("0");
		// run_converter("12");
		// run_converter("34");
		// run_converter("nan");
		// run_converter("-inf");
		// run_converter("inf");
		// run_converter("+inf");
		// run_converter("NULL");
		// run_converter(" ");
		try {
			run_converter((char *)&a);
			run_converter((char *)120);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
// #endif
	// {
	// 	// std::cout << std::numeric_limits<double>::max() << std::endl;
	// 	std::cout << std::numeric_limits<double>::min() << std::endl;
	// 	// std::cout << std::numeric_limits<float>::max() << std::endl;
	// 	// std::cout << std::numeric_limits<float>::min() << std::endl;
	// 	ScalarConverter::convert(argv[1]);
	// 	// std::cout << static_cast <float> (std::stof(argv[1])) << std::endl;
	// 	std::cout << std::numeric_limits<float>::max() << std::endl;
	// 	std::cout << std::numeric_limits<float>::min() << std::endl;
	// }
	return (0);
}
