/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:27:14 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/13 23:36:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &x, T &y)
{
	T temp = T(x);
	x = y;
	y = temp;
}

template <typename T> T &max(T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}

template <typename T> T &min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

#endif
