/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:57:17 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/27 17:57:50 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T> 
class Array
{
	public:
		Array(void);
		~Array(void);
		Array(const unsigned int n);
		Array(const Array &other);
		Array 				&operator=(const Array &other);
		T 					&operator[](unsigned int i) const;

		T 					&getVal(unsigned int loc) const;
		void 				setVal(unsigned int loc, T &val) const;

		const unsigned int 	&size(void) const;

	private:
		T 					*_arr;
		unsigned int		_n;
};

# include "Array.tpp"

#endif
