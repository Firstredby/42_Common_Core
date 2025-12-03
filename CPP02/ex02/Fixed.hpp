#pragma once

#include <iostream>
#include <cmath>
#include <stdint.h>

#define cout std::cout
#define endl std::endl

class Fixed {
	private:
		int 				i;
		static const int	ci = 8;
		
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int i);
		Fixed(const float f);
		Fixed& operator=(const Fixed& obj);
		~Fixed();

		bool	operator<=(const Fixed&) const ;
		bool	operator>=(const Fixed&) const ;
		bool	operator==(const Fixed&) const ;
		bool	operator!=(const Fixed&) const ;
		bool	operator>(const Fixed&) const ;
		bool	operator<(const Fixed&) const ;

		Fixed	operator+(const Fixed&) const;
		Fixed	operator-(const Fixed&) const;
		Fixed	operator*(const Fixed&) const;
		Fixed	operator/(const Fixed&) const;

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static const Fixed&	max(const Fixed&, const Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		static Fixed&	max(Fixed &, Fixed &);
		static Fixed&	min(Fixed &, Fixed &);

		int		toInt(void) const;
		float	toFloat(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);