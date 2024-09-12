/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:22:51 by sde-silv          #+#    #+#             */
/*   Updated: 2024/09/12 21:26:45 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor\n";
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor\n";
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer copy constructor\n";
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer copy assignment operator overload\n";
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
