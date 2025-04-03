/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:19:39 by sde-silv          #+#    #+#             */
/*   Updated: 2025/04/03 21:01:34 by sde-silv         ###   ########.fr       */
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
	{
		run_converter(argv[1]);
	}
	else
	{
		std::cout << "Usage: ./converter <value>" << std::endl;
		std::cout << "Usage(debug): ./dbg_converter <value>" << std::endl;
	}
	return (0);
}
