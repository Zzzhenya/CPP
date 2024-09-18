/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:05:23 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/18 22:15:28 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		Span sp = Span(0);

		sp.addNumber(22);
		sp.addNumber(99);
		sp.addNumber(12);
	}

	{
		Span sp = Span(2);

		sp.addNumber(22);
		sp.addNumber(99);
		sp.addNumber(12);
	}
	return (0);
}
