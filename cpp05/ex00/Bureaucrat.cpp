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
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
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

void	Bureaucrat::setGrade(unsigned int new_grade)
{
	this->_grade = new_grade;
}

void	Bureaucrat::upGrade(unsigned int val)
{
	int new_grade = getGrade() - val;
	if (new_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	setGrade((unsigned int)new_grade);
}

void	Bureaucrat::downGrade(unsigned int val)
{
	int new_grade = getGrade() + val;
	
	if (new_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	setGrade((unsigned int)new_grade);
}
