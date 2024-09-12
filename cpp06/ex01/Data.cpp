/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:19:22 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/12 21:19:32 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): a(-1), b(-1000), c(33), d(1000), e(120.42f), f(100.11), str("Hello")
{
	std::cout << "Data default constructor" << std::endl;
}

Data::Data(const Data &other): a(other.a), b(other.b), c(other.c), d(other.d), e(other.e), f(other.f), str(other.str)
{
	std::cout << "Data copy constructor" << std::endl;
}

Data	&Data::operator=(const Data &other)
{
	this->a = other.a;
	this->b = other.a;
	this->c = other.a;
	this->d = other.a;
	this->e = other.a;
	this->f = other.a;
	this->str = other.a;
	std::cout << "Data copy assignment operator overload" << std::endl;
	return (*this);
}

Data::Data(int mult): a(-1), b(-1000), c(33), d(1000), e(120.42f), f(100.11), str("World")
{
	a *= mult;
	b *= mult;
	c *= mult;
	d *= mult;
	e *= mult;
	f *= mult;
	std::cout << "Data parameter constructor" << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data destructor" << std::endl;
}

void Data::print_vals(void)
{
	std::cout << "int: " << a << " | ";
	std::cout << "long: " << b << " | ";
	std::cout << "char: " << c << " | ";
	std::cout << "uint: " << d << " | ";
	std::cout << "float: " << e << " | ";
	std::cout << "double: " << f << " | ";
	std::cout << "string: " << str<< std::endl;
}
