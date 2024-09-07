/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:49 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/08 01:19:18 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

A class with one static method "convert" 
that will takes a string representation of a C++ literal 
in its most common form 
and output its value in char,int,float, double
class must not be instanciable by users.

Except for char parameters, only the decimal notation will be used.

*/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>  // for strtol <- if using strtol
# include <string>

# define UKWN 0
# define EMPT 1
# define CHAR 2
# define STRG 3


class ScalarConverter
{
	public:
		~ScalarConverter(void);
		//static void	*convert(std::string val);
		static void		convert(const char *ptr);

	private:
		ScalarConverter(void);
};

#endif