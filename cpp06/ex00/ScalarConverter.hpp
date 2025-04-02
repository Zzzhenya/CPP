/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:17:49 by sde-silv          #+#    #+#             */
/*   Updated: 2025/04/02 15:30:13 by sde-silv         ###   ########.fr       */
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
# include <cstdlib>  // for atof atoi atol strtol 
# include <string>
# include <sstream>
# include <cmath>
# include <cctype>
# include <climits>
# include <limits>
//# include <cstdint>

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

# define CHAR 1
# define INT 2
# define DBL 3
# define FLT 4

class ScalarConverter
{
	public:
		template <typename T>
		static T			convert(const std::string val);
		// static void			converter(const std::string val);

	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter		&operator=(const ScalarConverter &other);
};


// std::ostream& operator<<(std::ostream& streamRef,const ScalarConverter& sconv);


#endif
