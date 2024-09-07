/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/08 00:40:13 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor\n";
}


ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor\n";
}

/**
 * static method "convert" that will takes 
 * as parameter a string representation of 
 * a C++ literal in its most common form 
 * and output its value in the following scalar types :
 *		char 	int 	float 	double
 * if input == non displayable character -> show error message
 * handle pseudo literals
 * 		-inff 	+inff 	nanf 	-inf 	+inf 	nan
 * handle oveflows, undeflows, non-sensical conversions,
 * 
 * 1. detect the type of the literal passed as parameter
 * 2. convert it from string to its actual type
 * 3. convert it explicitly to the three other data types
 * 4. display the results to std::cout
 * */

int detect_type(std::string &val)
{
	if (val.length() < 1 )
		return (EMPT);
	if (val.length() == 1) // not considering digits
		return (CHAR);
	else if (val.length() > 1)
		return (STRG);
	return (UKWN);
}

static int value_is_null(const char *ptr)
{
	if (!ptr)
		return (1);
	return (0);
}

void	ScalarConverter::convert(const char *ptr)
{
	if (value_is_null(ptr))
	{
		std::cout << "Value passed is a null pointer." << std::endl;
		return;
	}
	std::string		val = ptr;
	switch(detect_type(val))
	{
		case EMPT:
			std::cout << "Value is empty.\n";
			break;
		case CHAR:
			std::cout << val << " is a char.\n";
			break;
		case STRG:
			std::cout << val << " is a string.\n";
			break;
		default:
			std::cout << val << " is of unknown type.\n";
	}
}

// void	*ScalarConverter::convert(std::string val)
// {
// 	std::cout << val << std::endl;

// 	std::string *ret = new std::string(val);
// 	//return (ret);
// 	//return(reinterpret_cast<void*>((new std::string(val))));
	
// }