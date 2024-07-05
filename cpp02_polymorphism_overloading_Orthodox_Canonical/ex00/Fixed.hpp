#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& other); 

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					fixed_val;
		static const int	fract;
};

#endif