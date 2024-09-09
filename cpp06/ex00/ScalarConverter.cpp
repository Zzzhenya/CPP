/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/09 20:18:16 by sde-silv         ###   ########.fr       */
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

// int detect_type(const char *ptr)
int detect_type(const std::string &val)
{
	// std::string		val = ptr;
	// long int ret = strtol(ptr, NULL, 10);
	// std::cout << ret << std::endl;
	// (void)ret;
	try
	{
		std::cout << "result: " << std::stol(val, NULL, 10) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "exception: "<< e.what() << std::endl;
		return (UKWN);
	}

	if (val.empty())
		return (EMPT);
	if (val.length() == 1) // not considering digits
		return (CHAR);
	else if (val.length() > 1)
		return (STRG);
	return (UKWN);
}

int value_is_null(const char *ptr)
{
	if (!ptr)
		return (1);
	return (0);
}

int	value_is_empty(std::string &val)
{
	if (val.empty())
		return (1);
	return (0);
}

void	convert_to_char(int val)
{
	std::cout << "char:\t";
	if (val < 32 || val > 126)
		std::cout << "Non displayable" << std::endl;
	else if ((val >= 32 && val <= 126))
		std::cout << static_cast <char>(val) << std::endl;
}

// void try_char(std::string &val)
// {
// 	float ret = 0;
// }

int is_a_char(std::string &val)
{
	// Convert actual single character strings to char
	
	if (val.length() == 1)
	{
		//convert_to_char(val[0]);
		return (1);
	}
	// else
	// {
	// 	try
	// 	{
	// 		//ret = std::stol(val, NULL, 10);
	// 		if (!is_a_float(val) || !is_a_double(val))
	// 			return
	// 		ret = std::stol(val, 0);
	// 		std::cout << ret << std::endl;
	// 		convert_to_char(ret);
	// 		return (1);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 		std::cout << "char: Impossible" << std::endl;
	// 		return (0);
	// 	}
	// }
	return (0);
}

void try_int(std::string &val)
{
	try
	{
		int ret = std::stoi(val, 0);
		std::cout << "int:\t" << static_cast <int>(ret) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "int:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

void try_float(std::string &val)
{
	try
	{
		float ret = std::stof(val, 0);
		std::cout << "float:\t" << static_cast <float>(ret) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "float:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

void try_double(std::string &val)
{
	try
	{
		double ret = std::stod(val, 0);
		std::cout << "double:\t" << static_cast <double>(ret) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "double:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

int is_an_int(std::string &val)
{
	(void)val;
	std::cout << "is an int\n";
	return (1);
}

int is_a_double(std::string &val)
{
	(void)val;
	std::cout << "is a double\n";
	return (1);
}

int is_a_float(std::string &val)
{
	(void)val;
	std::cout << "is a float\n";
	return (1);
}

void	ScalarConverter::convert(const char *ptr)
{
	if (value_is_null(ptr))
	{
		std::cout << "Value passed is a null pointer." << std::endl;
		return;
	}
	std::string		val = ptr;
	if (value_is_empty(val))
	{
		std::cout << "Value is empty." << std::endl;
		return;
	}
	if (is_a_char(val))
	{
		convert_to_char(val[0]);
		try_int(val);
		try_double(val);
		try_float(val);
		return;
	}
	// if (is_an_int(val))
	// {
	// 	try_char; convert_to_int; try_double;try_float;\
	// 	return;
	// }
	// if (is_a_double(val))
	// {
	// 	try_char; try_int; convert_to_double;try_float;\
	// 	return;
	// }
	// if (is_a_float(val))
	// {
	// 	try_char; try_int; try_double ;convert_to_float;\
	// 	return;
	// }
}

// void	*ScalarConverter::convert(std::string val)
// {
// 	std::cout << val << std::endl;

// 	std::string *ret = new std::string(val);
// 	//return (ret);
// 	//return(reinterpret_cast<void*>((new std::string(val))));
	
// }