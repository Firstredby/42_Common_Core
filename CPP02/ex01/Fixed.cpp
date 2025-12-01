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

Fixed::Fixed(const int i)
{
	cout << "Int constructor called" << endl;
	this->i = i << this->ci;
}

Fixed::Fixed(const float f)
{
	cout << "Float constructor called" << endl;
	this->i = roundf(f * (1 << this->ci));
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

int		Fixed::toInt(void) const
{
	return this->i >> this->ci;
}

float	Fixed::toFloat(void) const
{
	return (float)this->i / (1 << this->ci);
}


int		Fixed::getRawBits(void) const
{
	// cout << "getRawBits member function called" << endl;
	return this->i;
}

void	Fixed::setRawBits(int const raw)
{
	this->i = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}