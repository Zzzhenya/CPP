/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:28:05 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:36:51 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define IDEA_LIMIT 100

class Brain
{
	public:
		Brain(void);
		~Brain(void);

	private:
		std::string ideas[IDEA_LIMIT];
};

#endif