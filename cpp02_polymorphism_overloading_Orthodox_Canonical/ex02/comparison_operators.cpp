#include "Fixed.hpp"

bool	Fixed::operator>(const Fixed& second)
{
	if (this->fixed_val > second.fixed_val)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed& second)
{
	if (this->fixed_val < second.fixed_val)
		return (1);
	else
		return (0);
}