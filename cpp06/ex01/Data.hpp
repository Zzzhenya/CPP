/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:14:44 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/12 21:19:50 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
		Data(void);
		~Data(void);
		Data(const Data &other);
		Data 			&operator=(const Data &other);
		Data(int mult);

		void 			print_vals(void);

	private:
		int 			a;
		long 			b;
		char 			c;
		unsigned int 	d;
		float 			e;
		double 			f;
		std::string 	str;
};

#endif
