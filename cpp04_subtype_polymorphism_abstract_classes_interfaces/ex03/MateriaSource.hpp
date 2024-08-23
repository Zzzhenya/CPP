#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define SOURCE_LIMIT 4

class AMateria;

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria *old);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *_source[SOURCE_LIMIT];
};


#endif