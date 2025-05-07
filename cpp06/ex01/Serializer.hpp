/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:21:13 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/07 18:12:43 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
//# include <cstdint>
// # include <stddef.h>
# include <iostream>
# include <stdint.h>

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &other);
		Serializer 			&operator=(const Serializer &other);
};

#endif
