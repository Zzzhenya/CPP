/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:26:06 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/17 16:26:09 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
		// A string variable initialized to "HI THIS IS BRAIN"
	std::string brain = "HI THIS IS BRAIN";
		// A pointer to the string.
	std::string *stringPTR = &brain;
		// A reference to the string.
	std::string &stringREF = brain;

	{
			// addresses
		std::cout << "Memory address of string variable: \t";
		std::cout << &brain << std::endl;

		std::cout << "Memory address of stringPTR: \t\t";
		std::cout << stringPTR << std::endl;
		
		std::cout << "Memory address of stringREF: \t\t";
		std::cout << &stringREF << std::endl;
	}

	{
			// values
		std::cout << "Value of string variable: \t\t";
		std::cout << brain << std::endl;

		std::cout << "Value of stringPTR: \t\t\t";
		std::cout << *stringPTR << std::endl;

		std::cout << "Value of stringREF: \t\t\t";
		std::cout << stringREF << std::endl;
	}

	return (0);
}
