#include "AForm.hpp"

AForm::AForm(void):_name("default"),_signed(0),
	_sign_grade(HIGHEST_GRADE),_exec_grade(LOWEST_GRADE)
{
	debug(std::cout << "AForm default constructor\n");
}

AForm::AForm(const AForm &other):_name(other._name),_signed(0),
	_sign_grade(other._sign_grade),_exec_grade(other._exec_grade)
{
	debug(std::cout << "AForm copy constructor\n");
}

/*
	Cannot copy assing _name, _sign_grade and _exec_grade - const
	Copy assignment non-functional, therefore private
*/
AForm	&AForm::operator=(const AForm &other)
{
	this->_signed = other._signed;
	debug(std::cout << "AForm copy assignment operator overload\n");
	return (*this);
}

AForm::AForm(std::string name, int sign_grade, int exec_grade):_name(name),
	_signed(0),_sign_grade(sign_grade),_exec_grade(exec_grade)
{
	if (sign_grade > LOWEST_GRADE || exec_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (sign_grade < HIGHEST_GRADE || exec_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	debug(std::cout << "AForm constructor\n");
}

AForm::~AForm(void)
{
	debug(std::cout << "AForm destructor\n");
}

bool	AForm::getStatus(void) const
{
	return (this->_signed);
}

std::string 	AForm::getName(void) const
{
	return(this->_name);
}

unsigned int 	AForm::getSignGrade(void) const
{
	return(this->_sign_grade);
}

unsigned int 	AForm::getExecGrade(void) const
{
	return(this->_exec_grade);
}

void	AForm::setStatus(bool status)
{
	if (this->_signed != status)
		this->_signed = status;
}

void AForm::beSigned(const Bureaucrat &bcat)
{
	unsigned int bcatgrade = bcat.getGrade();
	if (bcatgrade > getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (bcatgrade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	bcat.signForm(this);
}

void	AForm::execute(Bureaucrat const & executor) const
{
	unsigned int bcatgrade = executor.getGrade();
	if (bcatgrade > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (bcatgrade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	executor.executeForm(*this);
}


std::ostream& operator<<(std::ostream& streamRef,const AForm& AForm)
{
	streamRef << AForm.getName() << " \t\t: ";
	if (AForm.getStatus())
		streamRef << "Signed";
	else
		streamRef << "Unsigned";
	streamRef << "\tS: " << AForm.getSignGrade();
	streamRef << "  E: " << AForm.getExecGrade() << std::endl;
	return (streamRef);
}
