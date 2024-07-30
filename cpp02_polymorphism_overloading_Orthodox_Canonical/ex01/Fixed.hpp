/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:17:18 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 16:48:00 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed& 				operator=(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;

	private:
		int					fixed_val;
		static const int	fract = 8;
};

std::ostream& operator<<(std::ostream& streamRef,const Fixed& number);

#endif