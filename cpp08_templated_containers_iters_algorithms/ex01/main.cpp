/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:05:23 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/19 15:03:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <set>

void	add_a_num(Span &sp, int num)
{
	try
	{
		sp.addNumber(num);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	try_shortest_span(Span &sp)
{
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void	try_longest_span(Span &sp)
{
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void add_a_num_tests(void)
{
	{
		Span sp = Span(0);

		add_a_num(sp, 22);
		add_a_num(sp, 99);
		add_a_num(sp, 12);
		sp.printSpan();
	}

	{
		Span sp = Span(2);

		add_a_num(sp, 22);
		add_a_num(sp, 99);
		add_a_num(sp, 12);
		sp.printSpan();
	}
}

void span_tests(void)
{
	{
	 	Span sp = Span(5);
  		sp.addNumber(6);
  		sp.addNumber(3);
 		sp.addNumber(17);
  		sp.addNumber(9);
  		sp.addNumber(11);
  		std::cout << sp.shortestSpan() << std::endl;
  		sp.printSpan();
	}
	{
		Span sp = Span(5);
		try_shortest_span(sp);
		sp.printSpan();
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}

void bulk_add_tests(void)
{
	std::srand(std::time(0));
	{
		std::vector<int> vtr(10);
		for (std::vector<int>::iterator it = vtr.begin(); it != vtr.end(); it++)
			*it = std::rand() % 200;
		Span sp = Span(5);
		sp.addNumRange< std::vector<int> >(vtr.begin(), vtr.end());
	}
	{
		int len = 20;
		std::set<int> keys;
		for (int i = 0; i < len; i++)
			keys.insert(std::rand() % 200);
		Span sp = Span(len);
		sp.addNumRange< std::set<int> >(keys.begin(), keys.end());
	}
}

int main(void)
{
	add_a_num_tests();
	span_tests();
	bulk_add_tests();
	return (0);
}
