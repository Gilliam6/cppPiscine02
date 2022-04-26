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

	static Fixed& max(Fixed &ar, Fixed &ar1);
	static Fixed& min(Fixed &ar, Fixed &ar1);
	static Fixed const& max(Fixed const &ar, Fixed const &ar1);
	static Fixed const& min(Fixed const &ar, Fixed const &ar1);

	Fixed& operator= (const Fixed &ar);
	bool operator> (const Fixed &ar) const;
	bool operator< (const Fixed &ar) const;
	bool operator>= (const Fixed &ar) const;
	bool operator<= (const Fixed &ar) const;
	bool operator== (const Fixed &ar) const;
	bool operator!= (const Fixed &ar) const;
	Fixed operator+ (const Fixed &ar) const;
	Fixed operator- (const Fixed &ar) const;
	Fixed operator* (const Fixed &ar) const;
	Fixed operator/ (const Fixed &ar) const;
	Fixed& operator++ (void);
	Fixed operator++ (int);
	Fixed& operator-- (void);
	Fixed operator-- (int);



	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<< ( std::ostream &o, Fixed const &ar);

#endif
