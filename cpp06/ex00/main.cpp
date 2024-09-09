/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:19:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/09 02:40:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	{
		// void *ret = NULL;
		// ret = ScalarConverter::convert("A");
		// std::cout << (char *)ret << std::endl;
		// delete (char *)ret;
	}
	{
		// Char
		// char *val = NULL;
		// ScalarConverter::convert("A");
		// ScalarConverter::convert("");
		// ScalarConverter::convert(NULL);
		// ScalarConverter::convert(val);
		// ScalarConverter::convert("ABC");
		// ScalarConverter::convert("0");
		// ScalarConverter::convert("12");
		// ScalarConverter::convert("34");
		// ScalarConverter::convert("nan");
		// ScalarConverter::convert("-inf");
		// ScalarConverter::convert("inf");
		// ScalarConverter::convert("+inf");
		// ScalarConverter::convert("NULL");
		// ScalarConverter::convert(" ");
		std::cout << static_cast <char> (42) << std::endl;
		std::cout << static_cast <char> (42.3f) << std::endl;
		std::cout << static_cast <char> (0) << std::endl;
		std::cout << static_cast <char> ('a') << std::endl;
		std::cout << static_cast <char> ("a"[0]) << std::endl;
		std::cout << static_cast <char> (std::string("a")[0]) << std::endl;
		std::cout << static_cast <char> (std::string("0")[0]) << std::endl;
		std::cout << static_cast <char> (argv[1][0]) << std::endl;

	}
	return (0);
}