/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:52 by sde-silv          #+#    #+#             */
/*   Updated: 2024/11/14 23:46:21 by sde-silv         ###   ########.fr       */
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

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy constructor\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy assignment operator overload\n";
	return (*this);
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

int is_special_float(const std::string &val)
{
	if (val == "nanf" || val == "+inff" || val == "-inff" || val == "inff")
		return (1);
	return (0);
}

int is_special_double(const std::string &val)
{
	if (val == "nan" || val == "+inf" || val == "-inf" || val == "inf")
		return (1);
	return (0);
}

int	value_is_empty(const std::string &val)
{
	if (val.empty())
		return (1);
	return (0);
}


void	convert_to_char(const int val)
{
	std::cout << "char:\t";
	
	if ((val < 32  && val >= 0 )|| val == 127)
		std::cout << "Non displayable" << std::endl;
	else if (std::isprint(val))
		std::cout << "'" << static_cast <char>(val) << "'" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

int is_a_char(const std::string &val)
{
	if (val.length() == 1)
		return (1);
	return (0);
}

void try_int(const std::string &val)
{
	try
	{
		//int ret = std::stoi(val, 0);
		int ret = std::atoi(val.c_str());
		std::cout << "int:\t" << static_cast <int>(ret) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "int:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

void	convert_to_int(const std::string &val)
{
	try_int(val);
}

void try_float(const std::string &val)
{
	std::ostringstream 	os;

	std::cout << "float:\t";
	try
	{
		//float ret = std::stof(val);
		//double ret = std::stof(val);
		double ret = std::atof(val.c_str()); // really?
		os << static_cast<float>(ret);
	}
	catch(std::exception &e)
	{
		debug(std::cerr << e.what() << std::endl);
		std::cout << "Impossible" << std::endl;
		return;
	}
	try
	{
		if (!is_special_float(val) && !is_special_double(val))
		{
			if (val.find('.') == val.npos || !(os.str().find('+') && os.str().find('-')))
				os << ".0";
			else if (val.find('.') != val.npos && std::atol(val.c_str()) == std::atof(val.c_str()))
				os << ".0";
			// else if (val.find('.') != val.npos && std::stol(val) == std::stof(val))
			// 	os << ".0";
		}
		os << "f";
		std::cout << os.str() << std::endl;
	}
	catch(std::exception &e)
	{
		debug(std::cerr << e.what() << std::endl);
		std::cout << "Impossible" << std::endl;
		return;
	}
}


void	convert_to_float(const std::string &val)
{
	size_t		f_loc = val.find('f');

	if (f_loc == (val.length() - 1))
		try_float(val);
	else
		std::cout << "Impossible" << std::endl;
}


void try_double(const std::string &val)
{
	try
	{
		// double ret = std::stod(val, 0);
		double ret = std::atof(val.c_str());
		std::cout << "double:\t" << static_cast <double>(ret) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "double:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

void	try_char(const std::string &val)
{
	try
	{
		//float ret = std::stof(val, 0);
		float ret = std::atof(val.c_str());
		if (ret < 0 || ret > 127)
			std::cout << "char:\t" << "Impossible" << std::endl;
		else
			convert_to_char(ret);
	}
	catch (std::exception &e)
	{
		std::cout << "char:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

int is_an_int(const std::string &val)
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

int is_a_double(const std::string &val)
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



void	loop_through_digits(std::string &str, std::string::iterator &it)
{
	while (it != str.end())
	{
		if (std::isdigit(*it))
			it++;
		else
			break;
	}
}

int is_float_structure(std::string str)
{
	std::string::iterator it; 
      
    it = str.begin();
    loop_through_digits(str, it);
    if (it != str.end() && *it == '.')
    	it++;
    loop_through_digits(str, it); 
    // if (it != str.end() && *it == 'f')
    // 	it++;
	if (it == str.end())
		return (1);
	else
		return(0);
}
/*
ScalarConverter.cpp:266:5: error: this ‘if’ clause does not guard... [-Werror=misleading-indentation]
  266 |     if (it != str.end() && *it == 'f')
      |     ^~
ScalarConverter.cpp:268:9: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the ‘if’
  268 |         if (it == str.end())
      |         ^~

*/
int is_a_float(const std::string &val)
{
	try
	{
		if (is_float_structure(val) || is_special_float(val))
			std::atof(val.c_str());
			//std::stof(val);
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

int get_type(const std::string &val)
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

// void	ScalarConverter::convert(const char *ptr)
void	ScalarConverter::convert(const std::string val)
{
	if (value_is_empty(val))
	{
		std::cout << "Value is empty." << std::endl;
		return;
	}
	switch(get_type(val))
	{
		case CHAR:
			std::cout << std::endl << val << " is a char" << std::endl << std::endl;
			convert_to_char(val[0]); try_int(val); try_double(val); try_float(val);
			break;
		case INT:
			std::cout << std::endl << val << " is an int" << std::endl << std::endl;
			try_char(val); convert_to_int(val); try_double(val); try_float(val);
			break;
		case DBL:
			std::cout << std::endl << val << " is a double" << std::endl << std::endl;
			try_char(val); try_int(val); try_double(val); try_float(val);
			break;
		case FLT:
			std::cout << std::endl << val << " is a float" << std::endl << std::endl;
			try_char(val); try_int(val); try_double(val); convert_to_float(val);
			break;
		default:
			std::cout << std::endl << val << " is unknown" << std::endl << std::endl;
			try_char(val); try_int(val); try_double(val); try_float(val);
	}
}
