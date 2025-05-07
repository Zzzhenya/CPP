/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:52 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/07 17:57:53 by sde-silv         ###   ########.fr       */
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

int is_a_char(const std::string &val)
{
	if (val.length() == 1)
		return (1);
	return (0);
}

template <typename T>
void	try_char(T val, std::string str)
{
	(void)str;
		// else if (is_special_float(str) || is_special_double(str))
		// 	std::cout << "char:\t" << "Impossible" << std::endl;
	try
	{
		if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
			std::cout << "char:\t" << "Impossible" << std::endl;
		else if ((val < 32  && val >= 0 ) || val == 127)
			std::cout << "char:\t" << "Non displayable" << std::endl;
		else if (std::isprint(static_cast <char>(val)))
			std::cout << "char:\t" << "'" << static_cast <char>(val) << "'" << std::endl;
		else
			std::cout << "char:\t" << "Impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

template <typename T>
void	try_int(T val, std::string str)
{
	try
	{
		if (is_special_float(str) || is_special_double(str))
			std::cout << "int:\t" << "Impossible" << std::endl;
		else if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
			std::cout << "int:\t" << static_cast <int>(val) << std::endl;
		else
			std::cout << "int:\t" << "Impossible" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "int:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

template <typename T>
void try_float(T val, std::string str)
{

	try
	{
		//float ret = std::stof(val);
		//double ret = std::stof(val);
		// double ret = std::atof(val.c_str()); // really?
		// os << static_cast<float>(ret);
		if (val >= -(std::numeric_limits<float>::max()) && val <= std::numeric_limits<float>::max())
			std::cout << "float:\t" << static_cast<float>(val) << "f" << std::endl;
		else if (is_special_float(str) || is_special_double(str))
			std::cout << "float:\t" << static_cast<float>(val) << "f" << std::endl;
		else
			std::cout << "float:\t" << "Impossible" << std::endl;
	}
	catch(std::exception &e)
	{
		debug(std::cerr << e.what() << std::endl);
		std::cout << "float:\t" << "Impossible" << std::endl;
		return;
	}
}

template <typename T>
void try_double(T val, std::string str)
{
	try
	{
		if (is_special_float(str) || is_special_double(str))
			std::cout << "double:\t" << static_cast<double>(val) << std::endl;
		else if (val >= -(std::numeric_limits<double>::max()) && val <= std::numeric_limits<double>::max())
			std::cout << "double:\t" << static_cast <double>(val) << std::endl;
		else
			std::cout << "double:\t" << "Impossible" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "double:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}

void	convert_to_char(const std::string str)
{
	char val = str[0];

	if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
		std::cout << "char:\t" << "Impossible" << std::endl;
	else if ((val < 32  && val >= 0 ) || val == 127)
		std::cout << "char:\t"<< "Non displayable" << std::endl;
	else if (std::isprint(val))
		std::cout << "char:\t"<< "'" << static_cast <char>(val) << "'" << std::endl;
	else
		std::cout << "char:\t" << "Impossible" << std::endl;

	try_int<char>(static_cast <char>(val),str);
	try_float<char>(static_cast <char>(val), str);
	try_double<char>(static_cast <char>(val), str);
}

void	convert_to_int(const std::string &str)
{
	try
	{
		//int ret = std::stoi(val, 0);
		int val = std::atoi(str.c_str());
		try_char<int>(val, str);
		if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
			std::cout << "int:\t" << static_cast <int>(val) << std::endl;
		else
			std::cout << "int:\t" << "Impossible" << std::endl;
		try_float<int>(val, str);
		try_double<int>(val, str);
	}
	catch(std::exception &e)
	{
		std::cout << "int:\t" << "Impossible" << std::endl;
		debug(std::cerr << e.what() << std::endl);
	}
}


void	convert_to_float(const std::string &val)
{
	double ret = std::atof(val.c_str());

	try_char<float>(ret, val);
	try_int<float>(ret, val);
	// size_t		f_loc = val.find('f');
	// if (f_loc == (val.length() - 1) || is_special_float(val))
	// if (ret == std::numeric_limits<float>::infinity() || ret == -std::numeric_limits<float>::infinity()) // nanf??
	if (is_special_float(val))
		std::cout << "float:\t" << val << std::endl;
	else if (ret >= -(std::numeric_limits<float>::max()) && ret <= std::numeric_limits<float>::max())
	{
		// std::stringstream ss;
		// ss << ret;
		// ss << "f";
		// if (ss.str() == val)
			std::cout << "float:\t" <<  static_cast<float>(ret)  << "f" << std::endl;
		// else
		// 	std::cout << "float:\t" <<  val << std::endl;
	}
	else
		std::cout << "float:\t" << "Impossible" << std::endl;
	try_double<float>(ret, val);
}

void	convert_to_double(const std::string &val)
{
	double ret = std::atof(val.c_str());

	try_char<double>(ret, val);
	try_int<double>(ret, val);
	try_float<double>(ret, val);
	// size_t		f_loc = val.find('f');
	// if (f_loc == (val.length() - 1) || is_special_float(val))
	// if (ret == std::numeric_limits<float>::infinity() || ret == -std::numeric_limits<float>::infinity()) // nanf??
	if (is_special_double(val))
		std::cout << "double:\t" << val << std::endl;
	else if (ret >= -(std::numeric_limits<double>::max()) && ret <= std::numeric_limits<double>::max())
	{
		// std::stringstream ss;
		// ss << ret;
		// if (ss.str() == val)
			std::cout << "double:\t" <<  static_cast<double>(ret) << std::endl;
		// else
		// 	std::cout << "double:\t" <<  val << std::endl;
	}
	else
		std::cout << "double:\t" << "Impossible" << std::endl;
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
	std::string::iterator it =  str.begin();

	if (it != str.end() && (*it == '+' || *it == '-')) { it++;}
	loop_through_digits(str, it);
	if (it != str.end() && *it == '.') { it++;}
	loop_through_digits(str, it); 
	if (it != str.end() && *it == 'f') { it++;}
	
	if (it == str.end())
		return (1);
	else
		return(0);
}


int is_a_float(const std::string &val)
{
	try
	{
		if (is_float_structure(val) || is_special_float(val))
		{
			float ret = std::atof(val.c_str()); //std::stof(val);
			(void)ret;
		}
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
			convert_to_char(val);
			break;
		case INT:
			std::cout << std::endl << val << " is an int" << std::endl << std::endl;
			convert_to_int(val);
			break;
		case DBL:
			std::cout << std::endl << val << " is a double" << std::endl << std::endl;
			convert_to_double(val);
			break;
		case FLT:
			std::cout << std::endl << val << " is a float" << std::endl << std::endl;
			convert_to_float(val);
			break;
		default:
			std::cout << std::endl << val << " is unknown" << std::endl << std::endl;
	}
}
