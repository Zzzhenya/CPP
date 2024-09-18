/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:05:23 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/19 00:48:32 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

int main(void)
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
	return (0);
}
