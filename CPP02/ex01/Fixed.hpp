#pragma once

#include <iostream>
#include <cmath>

#define cout std::cout
#define endl std::endl

class Fixed {
	private:
		int 				i;
		static const int	ci = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed(const int i);
		Fixed(const float f);
		Fixed& operator=(const Fixed& obj);
		~Fixed();

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);