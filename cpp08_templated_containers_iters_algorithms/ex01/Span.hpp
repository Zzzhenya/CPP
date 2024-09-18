/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:04:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/19 01:50:19 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <iterator>
# include <cmath>
# include <exception>

class Span
{
	public:
		Span(const unsigned int N);
		~Span(void);

		void	addNumber(const int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	printSpan(void);
		void	addNumRange(const std::vector<int>::iterator &start, const std::vector<int>::iterator &end);

	private:
		std::vector<int>		_stash;
		const unsigned int 		_N;
};


#endif
