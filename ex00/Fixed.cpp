#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Standard constructor called\n";
	return;
}

Fixed::Fixed(const Fixed &ar)
{
	std::cout << "Overload copy constructor called\n";
	*this = ar;
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