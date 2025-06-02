/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:02:33 by sde-silv          #+#    #+#             */
/*   Updated: 2025/06/02 17:34:57 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>

/**
 * Parameters
 * 	1: the address of an array.
 * 	2: the length of the array.
 * 	3: a function that will be called on every element of the array
**/
/*
template <typename T> 
void iter(T arr[], std::size_t length, void (* func)(T &))
{
	if (!arr)
		return;
	for (std::size_t i=0; i < length; i++)
		func(arr[i]);
}

template <typename T> 
void iter(T arr[], std::size_t length, void (* func)(const T &))
{
	if (!arr)
		return;
	for (std::size_t i=0; i < length; i++)
		func(arr[i]);
}
*/
template <typename T, typename X> 
void iter(T arr[], std::size_t length, void (* func)(X &))
{
	if (!arr)
		return;
	for (std::size_t i=0; i < length; i++)
		func(arr[i]);
}

template < typename T >
void print(T &obj)
{
  std::cout << obj << std::endl;
  return;
}

template< typename T , T val>
void mult(T &obj)
{
  obj *= val;
  return;
}

#endif

