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
	_value = f * pow(2,_bits);
	std::cout << "Overload copy constructor with float\n";
	return ;
}

Fixed& Fixed::operator=(const Fixed &ar)
{
	std::cout <<  "Assignation operator called" <<  std::endl;
	this->_value = ar.getRawBits();
	return (*this);
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
	return (this->_value / pow(2, this->_bits));
}

std::ostream &operator<< ( std::ostream &o, Fixed const &ar)
{
	o << ar.toFloat();
	return (o);
}
