/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:31:20 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 18:49:01 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int i = 0;

	while (i < IDEA_LIMIT)
	{
		this->ideas[i] = "Something";
		i ++;
	}
	std::cout << "Brain default constructor called.";
	std::cout << std::endl;
}

Brain::~Brain(void)
{
	int i = 0;

	while (i < IDEA_LIMIT)
	{
		this->ideas[i] = "";
		i ++;
	}
	std::cout << "Brain destructor called.";
	std::cout << std::endl;
}

const std::string *Brain::getIdeas(void) const
{
	return (this->ideas);
}

void	Brain::setIdeas(std::string new_idea)
{
	int i = 0;

	while (i < IDEA_LIMIT)
	{
		this->ideas[i] = new_idea;
		i ++;
	}
}