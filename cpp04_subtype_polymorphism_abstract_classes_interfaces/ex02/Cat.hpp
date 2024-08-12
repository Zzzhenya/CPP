/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:29:08 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/12 20:00:08 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat& other);
        Cat&    operator=(const Cat& other);
    
        void        makeSound(void) const;
    
    private:
        Brain   *brain;
};

#endif