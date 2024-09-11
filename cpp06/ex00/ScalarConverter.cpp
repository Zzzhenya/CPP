/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/11 19:31:27 by sde-silv         ###   ########.fr       */
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
	if ((val < 32  && val >= 0 )|| val == 127)
		std::cout << "Non displayable" << std::endl;
	else if ((val >= 32 && val <= 126))
		std::cout << static_cast <char>(val) << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

int is_a_char(std::string &val)
{
	if (val.length() == 1)
		return (1);
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

void	convert_to_int(std::string &val)
{
	try_int(val);
}

void try_float(std::string &val)
{
	try
	{
		float ret = std::stof(val, 0);
		std::cout << "float:\t" << static_cast <float>(ret) << "f" << std::endl;
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

void	try_char(std::string &val)
{
	try
	{
		float ret = std::stof(val, 0);
		debug(std::cerr << ret << std::endl);
		convert_to_char(ret);
	}
	catch (std::exception &e)
	{
		std::cout << "char:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

int is_an_int(std::string &val)
{
	try
	{
		std::stringstream	ss(val);
		ss.exceptions(std::ios::failbit | std::ios::badbit); 
		int value;
		ss >> value;
		if (ss.eof())
			return (1);
		debug(std::cerr << "did not reach eof" << std::endl);
		return (0);
	}
	catch(const std::ios_base::failure& e)
	{
		debug(std::cerr << e.what() << std::endl);
		return (0);
	}
	return (0);
}

int is_a_double(std::string &val)
{
	try
	{
		std::stringstream	ss(val);
		ss.exceptions(std::ios::failbit | std::ios::badbit); 
		double value;
		ss >> value;
		if (ss.eof())
			return (1);
		debug(std::cerr << "did not reach eof" << std::endl);
		return (0);
	}
	catch(const std::ios_base::failure& e)
	{
		debug(std::cerr << e.what() << std::endl);
		return (0);
	}
	return (0);
}

// 	//ss << "f" ;
// 	// std::string a;
// 	// ss >> a;
// 	// std::cout << "float:kjashak\t" << a << std::endl;
// 		// Add a .0 if int, 
// 		// add a .0 if double but no .
// 		// add a f
// 	// std::cout << "float:\t" << static_cast <float>(ret) << "f" << std::endl;


void	convert_to_float(std::string &val)
{
	//size_t 		dec_loc = val.find('.');
	size_t		f_loc = val.find('f');

	std::cout << "float:\t";
	if (f_loc == (val.length() - 1))
	{
		try
		{
			float ret = std::stof(val, 0);
			std::cout << static_cast<float>(ret);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Impossible" << std::endl;
			return;
		}
		if (val.find('.') == val.npos)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
}

int is_float_structure(std::string &str)
{
	std::string::iterator it; 
      
    it = str.begin();
    while (it != str.end())
    {
    	if (std::isdigit(*it))
    		it++;
    	else
    		break;
    }
    if (it != str.end() && *it == '.')
    	it++;
    while (it != str.end())
    {
    	if (std::isdigit(*it))
    		it++;
    	else
    		break;
    }  
    if (it != str.end() && *it == 'f')
    	it++;
	if (it == str.end())
		return (1);
	else
		return(0);
}

int is_special_float(std::string &val)
{
	if (val == "nanf" || val == "+inff" || val == "-inff" || val == "inff")
		return (1);
	return (0);
}

int is_a_float(std::string &val)
{
	try
	{
		if (is_float_structure(val) || is_special_float(val))
			std::stof(val);
		else
			return (0);
		return (1);
	}
	catch(std::exception &e)
	{
		debug(std::cerr << e.what() << std::endl);
		return (0);
	}
}

int get_type(std::string &val)
{
	if (is_a_char(val))
		return (CHAR);
	if (is_an_int(val))
		return (INT);
	if (is_a_double(val))
		return (DBL);
	if (is_a_float(val))
		return (FLT);
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
	if (value_is_empty(val))
	{
		std::cout << "Value is empty." << std::endl;
		return;
	}
	switch(get_type(val))
	{
		case CHAR:
			convert_to_char(val[0]); try_int(val); try_double(val); try_float(val);
			break;
		case INT:
			try_char(val); convert_to_int(val); try_double(val); try_float(val);
			break;
		case DBL:
			try_char(val); try_int(val); try_double(val); try_float(val);
			break;
		case FLT:
			try_char(val); try_int(val); try_double(val); convert_to_float(val);
			break;
		default:
			try_char(val); try_int(val); try_double(val); try_float(val);
	}
}
