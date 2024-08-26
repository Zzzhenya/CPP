#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if ( _source[i] != NULL)
			delete _source[i];
	}
}

/**
 * Copies the Materia passed as a parameter 
 * and store it in memory so it can be cloned later. 
 * Like the Character, the MateriaSource can know at most 4 Materias. 
 * They are not necessarily unique.
 * */
void MateriaSource::learnMateria(AMateria *old)
{
	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if (_source[i] == NULL)
		{
			_source[i] = old;
			return;
		}
	}
	std::cout << "Source is full\n";
}

/**
 * Returns a new Materia. 
 * The latter is a copy of the Materia previously learned by 
 * the MateriaSource whose type equals the one passed as parameter. 
 * Returns 0 if the type is unknown.
 * */
AMateria* MateriaSource::createMateria(std::string const & type)
{
	// AMateria *cpy = NULL;

	for (int i = 0; i < SOURCE_LIMIT; i++)
	{
		if ( _source[i] != NULL && type == _source[i]->getType())
		{
			return (_source[i]->clone());
		}
	}
	return (0);
}