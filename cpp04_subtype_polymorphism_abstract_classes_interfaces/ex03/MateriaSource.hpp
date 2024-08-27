/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:59:29 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 20:17:00 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>
# include "IMateriaSource.hpp"
# include "debug.hpp"

# define SOURCE_LIMIT 4

class AMateria;

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource	&operator=(const MateriaSource &other);
		
		void			learnMateria(AMateria *temp);
		AMateria*		createMateria(std::string const & type);

		void			print_source(void);

	private:
		AMateria		*getSourceItem(int idx) const;
		AMateria 		*_source[SOURCE_LIMIT];
};

#endif