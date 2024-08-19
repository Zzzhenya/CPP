/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:28:05 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/19 21:55:36 by sde-silv         ###   ########.fr       */
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
		Brain(const Brain &other);
		Brain operator=(const Brain &other);

		const std::string	*getIdeas(void) const;
		void		setIdeas(std::string new_idea);

	private:
		std::string ideas[IDEA_LIMIT];
};

#endif