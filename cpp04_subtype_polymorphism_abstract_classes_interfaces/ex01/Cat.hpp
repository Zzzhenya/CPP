/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:00 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/16 20:02:24 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal//, public Brain
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat& other);
        Cat&                operator=(const Cat& other);
        Cat(std::string new_idea);

        void                makeSound(void) const;
        void                setIdeas(std::string new_idea);
        const std::string   *getIdeas(void) const;
    
    private:
        Brain       *brain;
};

#endif