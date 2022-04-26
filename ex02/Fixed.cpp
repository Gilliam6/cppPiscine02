#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Standard constructor called\n";
	return ;
}

Fixed::Fixed(const Fixed &ar)
{
	std::cout << "Overload copy constructor called\n";
	*this = ar;
	return ;
}

Fixed::Fixed(const int i): _value(i << _bits)
{
	std::cout << "Overload copy constructor with int\n";
	return ;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_bits));
	std::cout << "Overload copy constructor with float\n";
	return ;
}

Fixed& Fixed::operator=(const Fixed &ar)
{
	std::cout <<  "Assignation operator called" <<  std::endl;
	this->_value = ar.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &ar) const
{
	return (this->_value > ar._value);
}

bool Fixed::operator<(const Fixed &ar) const
{
	return (this->_value < ar._value);
}

bool Fixed::operator>=(const Fixed &ar) const
{
	return (this->_value >= ar._value);
}

bool Fixed::operator<=(const Fixed &ar) const
{
	return (this->_value <= ar._value);
}

bool Fixed::operator==(const Fixed &ar) const
{
	return (this->_value == ar._value);
}

bool Fixed::operator!=(const Fixed &ar) const
{
	return (this->_value == ar._value);
}

Fixed Fixed::operator+(const Fixed &ar) const
{
	Fixed a;
	a.setRawBits(this->_value + ar._value);
	return (a);
}

Fixed Fixed::operator-(const Fixed &ar) const
{
	Fixed a;
	a.setRawBits(this->_value - ar._value);
	return (a);
}

Fixed Fixed::operator*(const Fixed &ar) const
{
	Fixed a;
	a.setRawBits((ar._value >> _bits) * _value);
	return (a);
}

Fixed Fixed::operator/(const Fixed &ar) const
{
	Fixed a;
	a.setRawBits((_value << _bits) / ar._value);
	return (a);
}
Fixed& Fixed::operator++(void) //++a
{
	setRawBits(_value + 1);
	return (*this);
}

Fixed Fixed::operator++(int) //a++
{
	Fixed a(*this);
	setRawBits(_value + 1);
	return (a);
}

Fixed& Fixed::operator--(void) //--a
{
	setRawBits(_value - 1);
	return (*this);
}

Fixed Fixed::operator--(int) //a--
{
	Fixed a(*this);
	setRawBits(_value - 1);
	return (a);
}

Fixed& Fixed::max(Fixed &ar, Fixed &ar1)
{
	if (ar > ar1)
		return (ar);
	return (ar1);
}

Fixed& Fixed::min(Fixed &ar, Fixed &ar1)
{
	if (ar > ar1)
		return (ar);
	return (ar1);
}

Fixed const& Fixed::max(Fixed const &ar, Fixed const &ar1)
{
	if (ar > ar1)
		return (ar);
	return (ar1);
}

Fixed const& Fixed::min(Fixed const &ar, Fixed const &ar1)
{
	if (ar > ar1)
		return (ar);
	return (ar1);
}

Fixed::~Fixed()
{
	std::cout << "Destrurctor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int     Fixed::toInt() const
{
	return (this->_value >> this->_bits);
}

float   Fixed::toFloat() const
{
	return((float)this->_value / (float)(1 << this->_bits));
}

std::ostream &operator<< ( std::ostream &o, Fixed const &ar)
{
	o << ar.toFloat();
	return (o);
}
