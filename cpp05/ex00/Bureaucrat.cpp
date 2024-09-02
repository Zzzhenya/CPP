#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("default"),_grade(LOWEST_GRADE)
{
	debug(std::cout << "Bureaucrat default constructor\n");
}

Bureaucrat::~Bureaucrat(void)
{
	debug(std::cout << "Bureaucrat destructor\n");
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):_name(name), _grade(grade)
{
	debug(std::cout << "Bureaucrat constructor\n");
}

const std::string		&Bureaucrat::getName() const
{
	return (this->_name);
}

const unsigned int		&Bureaucrat::getGrade() const
{
	return (this->_grade);
}
