/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:05:23 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/18 23:45:00 by sde-silv         ###   ########.fr       */
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

int main(void)
{
	{
		Span sp = Span(0);

		add_a_num(sp, 22);
		add_a_num(sp, 99);
		add_a_num(sp, 12);
	}

	{
		Span sp = Span(2);

		add_a_num(sp, 22);
		add_a_num(sp, 99);
		add_a_num(sp, 12);
	}
	return (0);
}
