#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

#define cout std::cout
#define endl std::endl

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string&	gettype() const;
		void				setType(std::string type);
};

#endif