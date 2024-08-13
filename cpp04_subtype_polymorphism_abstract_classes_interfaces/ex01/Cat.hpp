/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:29:08 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/13 12:08:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal, virtual public Brain
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat& other);
        Cat&    operator=(const Cat& other);
    
        void        makeSound(void) const;
        std::string *getIdeas(void);
        void        setIdeas(std::string &new_idea);
    
    private:
        Brain   *brain;
};

#endif