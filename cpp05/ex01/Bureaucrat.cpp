#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("default"),_grade(LOWEST_GRADE)
{
	debug(std::cout << "Bureaucrat default constructor\n");
}

Bureaucrat::~Bureaucrat(void)
{
	debug(std::cout << "Bureaucrat destructor\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name),_grade(other._grade)
{
	debug(std::cout << "Bureaucrat copy constructor\n");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	debug(std::cout << "Bureaucrat copy assignment operator overload\n");
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
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

void	Bureaucrat::upGrade(void)
{
	int new_grade = getGrade() - 1;
	if (new_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	setGrade((unsigned int)new_grade);
}

void	Bureaucrat::downGrade(void)
{
	int new_grade = getGrade() + 1;

	if (new_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	setGrade((unsigned int)new_grade);
}

void	Bureaucrat::signForm(Form *form) const
{
	if (form->getStatus())
	{
		std::cout << this->getName();
		std::cout << " couldn’t sign " << form->getName();
		std::cout << " because form is already signed." << std::endl;
		return;
	}
	form->setStatus(1);
	{
		std::cout << this->getName();
		std::cout << " signed " << form->getName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& streamRef,const Bureaucrat& bcat)
{
	streamRef << bcat.getName() << ", bureaucrat grade ";
	streamRef << bcat.getGrade() << "." << std::endl;
	return (streamRef);
}