/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:19:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/11 23:36:47 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Too many arguments." << std::endl;
#ifdef _DEBUG
	{
		char *val = NULL;
		ScalarConverter::convert("A");
		ScalarConverter::convert("");
		ScalarConverter::convert(NULL);
		ScalarConverter::convert(val);
		ScalarConverter::convert("ABC");
		ScalarConverter::convert("0");
		ScalarConverter::convert("12");
		ScalarConverter::convert("34");
		ScalarConverter::convert("nan");
		ScalarConverter::convert("-inf");
		ScalarConverter::convert("inf");
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("NULL");
		ScalarConverter::convert(" ");
	}
#endif
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
