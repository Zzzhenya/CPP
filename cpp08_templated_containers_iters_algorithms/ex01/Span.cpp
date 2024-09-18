/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:03:01 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/18 22:15:47 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int N): _N(N)
{
	_stash.reserve(N);
	std::cout << "Span constructor" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor" << std::endl;
}

void Span::addNumber(int number)
{
	if (_stash.size() < _N)
	{
		_stash.push_back(number);
		std::cout << "added " << number << std::endl;
	}
	else
		std::cout << "full\n";
}

