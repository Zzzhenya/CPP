/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:22:25 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/08 16:57:50 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <typeinfo>

# define CLAP_HIT_POINTS 10
# define CLAP_ENERGY_POINTS 10
# define CLAP_DAMAGE_POINTS 0

class ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(const ClapTrap& other);
		ClapTrap(const std::string& new_name);
		ClapTrap&		operator=(const ClapTrap& other);

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

		unsigned int	getAttackDamage(void);
		void			print_score(void);
		std::string		get_class_name(void);

	private:
		std::string 	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif
