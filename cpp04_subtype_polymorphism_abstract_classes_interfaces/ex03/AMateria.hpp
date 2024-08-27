/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:04:55 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 22:09:55 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "debug.hpp"

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class Cure;

class Ice;

class AMateria
{
	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(const AMateria &other);
		AMateria(std::string const & type);
		
		std::string const	&getType() const;	
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;

	private:
		AMateria			&operator=(const AMateria &other);
};

#endif
