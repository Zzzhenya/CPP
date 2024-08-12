/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:31:57 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 20:00:15 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog& other);
        Dog&    operator=(const Dog& other);
    
        void    makeSound(void) const;

    private:
        Brain   *brain;
};

#endif