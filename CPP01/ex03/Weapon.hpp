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
		std::string	gettype();
		void		settype(std::string type);
};

#endif