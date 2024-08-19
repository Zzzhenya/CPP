/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/19 21:04:56 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(const AMateria &other);
		AMateria operator=(const AMateria &other);

		AMateria(std::string const & type);
		
		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const;
		//virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
};

#endif