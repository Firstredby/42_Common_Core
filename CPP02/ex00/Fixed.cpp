#include "Fixed.hpp"

Fixed::Fixed()
{
	this->i = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& obj)
{
	cout << "Copy constructor called" << endl;
	Fixed::operator=(obj);
}
Fixed& Fixed::operator=(const Fixed& obj)
{
	cout << "Copy assignment constructor called" << endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->i;
}
void	Fixed::setRawBits(int const raw)
{
	this->i = raw;
}