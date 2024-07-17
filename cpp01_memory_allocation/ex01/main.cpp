/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:08:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/07/17 16:08:46 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	make_horde(int count)
{
	int i = 0;
	Zombie *horde = NULL;

	horde = zombieHorde(count, "Aaaaa");
	if (horde == NULL)
		return ;
	while (i < count)
	{
		std::cout << (i + 1) << ": ";
		horde[i].announce();
		i++;
	}
	delete[] horde;
	std::cout << std::endl;
}

int	main(void)
{
	make_horde(0);
	make_horde(5);
	make_horde(-2);
	make_horde(100);	
	return (0);
}
