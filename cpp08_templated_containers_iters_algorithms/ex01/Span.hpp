/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:04:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/18 22:16:12 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <iterator>

class Span
{
	public:
		Span(const unsigned int N);
		~Span(void);

		void	addNumber(int number);

	private:
		std::vector<int>		_stash;
		const unsigned int 		_N;
};


#endif
