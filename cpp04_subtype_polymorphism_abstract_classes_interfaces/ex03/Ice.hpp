/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:11 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 14:17:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "debug.hpp"

# define TYPE_ICE "ice"

class Ice: public AMateria
{
    public:
        Ice(void);
        ~Ice(void);
        Ice(const Ice &other);
        Ice     &operator=(const Ice &other);

        Ice    *clone() const;
        void    use(ICharacter& target);
};

#endif