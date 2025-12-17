#include "Fixed.hpp"

Fixed::Fixed()
{
	this->i = 0;
	// cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& obj)
{
	// cout << "Copy constructor called" << endl;
	Fixed::operator=(obj);
}

Fixed::Fixed(const int i)
{
	this->i = i << this->ci;
}

Fixed::Fixed(const float f)
{
	this->i = roundf(f * (1 << this->ci));
}

Fixed::~Fixed()
{
	// cout << "Destructor called" << endl;
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
	return this->i;
}

void	Fixed::setRawBits(int const raw)
{
	this->i = raw;
}

Fixed& Fixed::operator=(const Fixed& obj)
{

	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return *this;
}

bool	Fixed::operator>=(const Fixed& val) const
{
	return (this->getRawBits() >= val.getRawBits());
}

bool	Fixed::operator<=(const Fixed& val) const
{
	return (this->getRawBits() <= val.getRawBits());
}

bool	Fixed::operator==(const Fixed& val) const
{
	return (this->getRawBits() == val.getRawBits());
}

bool	Fixed::operator!=(const Fixed& val) const
{
	return (this->getRawBits() != val.getRawBits());
}

bool	Fixed::operator>(const Fixed& val) const
{
	return (this->getRawBits() > val.getRawBits());
}

bool	Fixed::operator<(const Fixed& val) const
{
	return (this->getRawBits() < val.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& val) const
{
	return (this->toFloat() + val.toFloat());
}

Fixed	Fixed::operator-(const Fixed& val) const
{
	return (this->toFloat() - val.toFloat());
}

Fixed	Fixed::operator*(const Fixed& val) const
{
	return (this->toFloat() * val.toFloat());
}

Fixed	Fixed::operator/(const Fixed& val) const
{
	if (val.i == 0)
	{
		std::cerr << "Can't divide by zero" << endl;
		return (0);
	}
	return (this->toFloat() / val.toFloat());
}

Fixed&	Fixed::operator++()
{
	++i;
	return *this;
};

Fixed&	Fixed::operator--()
{
	--i;
	return *this;
};

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++i;
	return tmp;
};

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--i;
	return tmp;
};

const Fixed&	Fixed::max(const Fixed& val1, const Fixed& val2)
{
	return (val1 >= val2 ? val1 : val2);
}
const Fixed&	Fixed::min(const Fixed& val1, const Fixed& val2)
{
	return (val1 <= val2 ? val1 : val2);
}
Fixed&	Fixed::max(Fixed& val1, Fixed& val2)
{
	return (val1 >= val2 ? val1 : val2);
}
Fixed&	Fixed::min(Fixed& val1, Fixed& val2)
{
	return (val1 <= val2 ? val1 : val2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
