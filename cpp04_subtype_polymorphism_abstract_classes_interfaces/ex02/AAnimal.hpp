/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:24:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 20:01:37 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
    public:
        AAnimal(void);
        virtual ~AAnimal(void);
        AAnimal(const AAnimal& other);
        AAnimal&     operator=(const AAnimal& other);
        
        virtual void            makeSound(void) const = 0;
        std::string             getType(void) const;

    protected:
        std::string type;
};

#endif