/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:01:09 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/30 14:13:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed&				operator=(const Fixed& other); 

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					fixed_val;
		static const int	fract = 8;
};

#endif
