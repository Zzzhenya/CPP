#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed(void);
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& other); 

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					fixed_val;
		static const int	fract = 8;
};

#endif