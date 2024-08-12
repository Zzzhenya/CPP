/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:24:40 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:37:17 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    public:
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal& other);
        Animal&     operator=(const Animal& other);
        
        virtual void            makeSound(void) const;
        std::string             getType(void) const;

    protected:
        std::string type;
};

#endif