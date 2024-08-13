#include "AMateria.hpp"

AMateria::AMateria(std::string const & new_type)
{
	this->type = new_type;
	std::cout << "AMateria constructor called.";
	std::cout << " type: " << new_type << std::endl;
}

std::string const &AMateria::getType() const //Returns the materia type
{
	return(this->type);
}
// virtual AMateria* clone() const = 0;
// virtual void use(ICharacter& target);