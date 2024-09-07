/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:19:39 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/08 01:14:39 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(void)
{
	{
		// void *ret = NULL;
		// ret = ScalarConverter::convert("A");
		// std::cout << (char *)ret << std::endl;
		// delete (char *)ret;
	}
	{
		// Char
		char *val = NULL;
		ScalarConverter::convert("A");
		ScalarConverter::convert("");
		ScalarConverter::convert(NULL);
		ScalarConverter::convert(val);
		ScalarConverter::convert("ABC");
		ScalarConverter::convert("0");
		ScalarConverter::convert("12");

	}
	return (0);
}