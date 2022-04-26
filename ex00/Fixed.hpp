#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{

private:

	int					_value;
	static const int 	_bits;

public:
	Fixed();
	~Fixed();

	Fixed(const Fixed &ar);
	Fixed& operator= (const Fixed &ar);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};
#endif
