/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:03:01 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/18 23:45:36 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int N): _N(N)
{
	_stash.reserve(N);
	std::cout << "Span constructor" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span destructor" << std::endl;
}

void Span::addNumber(const int number)
{
	if (_stash.size() < _N)
	{
		_stash.push_back(number);
		std::cout << "Added " << number << std::endl;
	}
	else
		throw std::length_error("Exception: length_error: The stash is full");
}

