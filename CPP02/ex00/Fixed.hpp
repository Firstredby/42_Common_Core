#pragma once

#include <iostream>

#define cout std::cout
#define endl std::endl

class Fixed {
	private:
		int 		i;
		static const int	ci = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};