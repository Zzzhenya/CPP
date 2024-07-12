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
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other); 

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& second) const;
		bool	operator<(const Fixed& second) const;
		bool	operator>=(const Fixed& second);
		bool	operator<=(const Fixed& second);
		bool	operator==(const Fixed& second);
		bool	operator!=(const Fixed& second);

		Fixed operator+(const Fixed& second);
		Fixed operator-(const Fixed& second);
		Fixed operator*(const Fixed& second);
		Fixed operator/(const Fixed& second);

		Fixed&	operator++(void); //++a
		Fixed	operator++(int val); //a++
		Fixed&	operator--(void); //--a
		Fixed	operator--(int val); //a--

		static Fixed&		min(Fixed& first, Fixed& second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);

	private:
		int					fixed_val;
		static const int	fract = 8;
};

std::ostream& operator<<(std::ostream& streamRef,const Fixed& number);

#endif