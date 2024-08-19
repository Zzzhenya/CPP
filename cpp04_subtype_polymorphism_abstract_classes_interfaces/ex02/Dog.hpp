/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/19 19:31:05 by sde-silv         ###   ########.fr       */
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
        Dog&                operator=(const Dog& other);
        Dog(std::string new_idea);
    
        void                makeSound(void) const;
        const std::string   *getIdeas(void) const;
        void                setIdeas(std::string new_idea);

    private:
        Brain       *brain; 
};

#endif