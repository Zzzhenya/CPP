/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:59:56 by sde-silv          #+#    #+#             */
/*   Updated: 2024/08/27 17:24:03 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/**
 * Orthodox canonical form functions
 * 
 * 1. Default constructor
 * 2. Destructor
 * 3. Copy constructor
 * 4. Copy assignment operator overload
 */
MateriaSource::MateriaSource(): IMateriaSource()
{
	debug(std::cout << "MateriaSource default constructor.\n");
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	debug(std::cout << "MateriaSource destructor.\n");
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if ( _source[i] != NULL)
			delete _source[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other):IMateriaSource()
{
	debug(std::cout << "MateriaSource copy construcotr\n");
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if (other._source[i] != NULL)
			this->_source[i] = other._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	debug(std::cout << "MateriaSource copy assignment operator\n");
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if (other._source[i] != NULL)
		{
			if (this->_source[i] != NULL)
				delete this->_source[i];
			this->_source[i] = other._source[i]->clone();
		}
		else
			this->_source[i] = NULL;
	}
	return (*this);
}

/**
 * Copies the Materia passed as a parameter 
 * and store it in memory so it can be cloned later. 
 * Like the Character, the MateriaSource can know at most 4 Materias. 
 * They are not necessarily unique.
 * */
void MateriaSource::learnMateria(AMateria *temp)
{
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if (_source[i] == NULL && temp != NULL)
		{
			_source[i] = temp->clone();
			return;
		}
	}
	if (temp == NULL)
		debug(std::cout << "null pointer\n");
	else
		debug(std::cout << "Source is full\n");
}

/**
 * Returns a new Materia. 
 * The latter is a copy of the Materia previously learned by 
 * the MateriaSource whose type equals the one passed as parameter. 
 * Returns 0 if the type is unknown.
 * */
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if ( _source[i] != NULL && type == _source[i]->getType())
		{
			return (_source[i]->clone());
		}
	}
	debug(std::cout << type << " is not available in source\n");
	return (0);
}

AMateria		*MateriaSource::getSourceItem(int idx)
{
	if (this->_source[idx] == NULL)
		return (0);
	return(this->_source[idx]);	
}

void			MateriaSource::print_source(void)
{
	AMateria *curr = NULL;
	
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		curr = this->getSourceItem(i);
		if (curr != NULL)
			std::cout << curr->getType() << " ";
		else
			std::cout << "empty ";
	}
	std::cout << std::endl;
}