/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:03:01 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/19 14:57:26 by sde-silv         ###   ########.fr       */
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
		throw std::logic_error("Exception: The stash is full");
}

/*
	the shortest span or the longest span (or distance, if you prefer) 
	between all the numbers stored, 
	and return it. 
	If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.
*/
int Span::shortestSpan(void)
{
	if (_stash.size() < 2)
		throw std::logic_error("Exception: shortestSpan: Unable to find span");
	std::vector<int> cpy = _stash;
	std::sort(cpy.begin(), cpy.end());

	// check whether it should be sorted until end ?

	int ret = 0;
	for (std::vector<int>::iterator it = cpy.begin(); it != cpy.end(); it++)
	{
		if (it + 1 != cpy.end())
		{
			if (it == cpy.begin() || (std::abs(*(it + 1) - *(it)) < ret))
				ret = std::abs(*(it + 1) - *(it));
		}
	}
	return (ret);
}

int Span::longestSpan(void)
{
	if (_stash.size() < 2)
		throw std::logic_error("Exception: longestSpan: Unable to find span");
	std::vector<int> cpy = _stash;
	std::sort(cpy.begin(), cpy.end());

	// check whether it should be sorted until end ?

	int max = cpy[cpy.size() - 1];
	int min = cpy[0];

	return(std::abs(max - min));
}

void	Span::printSpan(void)
{
	if (_stash.size() < 1 && _N > 0)
		std::cout << "Stash:\tEmpty" << std::endl;
	else if (_N > 0)
	{
		std::cout << "Stash:\t";
		for (std::vector<int>::iterator it = _stash.begin(); it != _stash.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "Stash:\t0 size" << std::endl;

}

