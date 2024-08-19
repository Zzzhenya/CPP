/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:05:05 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/19 21:05:06 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

# define TYPE_CURE "cure"

class Cure: public AMateria
{
    public:
        Cure(void);
        ~Cure(void);
        Cure(const Cure &other);
        // Cure operator=(const Cure &other);

        Cure* clone() const;
};

#endif