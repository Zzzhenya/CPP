/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:31:57 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 17:41:08 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
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