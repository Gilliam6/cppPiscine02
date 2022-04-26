#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed{

private:

	int					_value;
	static const int 	_bits = 8;

public:
	Fixed();
	~Fixed();

	Fixed(const Fixed &ar);
	Fixed(const int i);
	Fixed(const float f);
	Fixed& operator= (const Fixed &ar);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<< ( std::ostream &o, Fixed const &ar);

#endif
