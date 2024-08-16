/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:28:05 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 18:48:56 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define IDEA_LIMIT 3

class Brain
{
	public:
		Brain(void);
		~Brain(void);

		const std::string	*getIdeas(void) const;
		void		setIdeas(std::string new_idea);

	private:
		std::string ideas[IDEA_LIMIT];
};

#endif