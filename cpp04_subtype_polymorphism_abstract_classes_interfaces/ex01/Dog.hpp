/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:31:57 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 12:21:23 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal, virtual public Brain
{
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog& other);
        Dog&        operator=(const Dog& other);
    
        void        makeSound(void) const;
        std::string *getIdeas(void);
        void        setIdeas(std::string new_idea);

    private:
        Brain   *brain;
};

#endif