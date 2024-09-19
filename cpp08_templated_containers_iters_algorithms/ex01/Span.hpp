/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:04:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/19 15:04:15 by sde-silv         ###   ########.fr       */
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

		void					addNumber(const int number);
		int						shortestSpan(void);
		int						longestSpan(void);
		void					printSpan(void);

		template <typename T> 
		void 					addNumRange(const typename T::iterator &start, const typename T::iterator &end);

	private:
		std::vector<int>		_stash;
		const unsigned int 		_N;
};

template <typename T> 
void Span::addNumRange(const typename T::iterator &start, const typename T::iterator &end)
{
	if (start == end)
	{
		std::cout << "start == end\n";
		return;
	}
	try
	{
		for (typename T::iterator it = start; it != end; it++)
		{
			this->addNumber(*it);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

#endif
