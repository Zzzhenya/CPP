/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:36:11 by sde-silv          #+#    #+#             */
/*   Updated: 2025/06/21 17:53:51 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"


/*
only digits: 0 to 9 -> result after calculation can be larger than 10
process:
if success: print out to cout
if error: print out to cerr
operations: + - / *
no need to handle brackets && decimal numbers

assumptions from example : space is the delimiter

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" => 42

3 4 + 5 6 + × => (3 + 4) × (5 + 6) => 77

./RPN "1" => 1

non RPN
./RPN "+ +"
./RPN "1 1"

*/

int main(int argc, char **argv)
{
	if (argc != 2)
		error("write the expression in reverse polish notation with 0-9 +*-/");
	else
	{
		try
		{
			RPN calc;
			calc.calcRPN(argv[1]);
		}
		catch (std::exception &e)
		{
			error("Error: " << e.what());
		}
	}
	return (0);
}
