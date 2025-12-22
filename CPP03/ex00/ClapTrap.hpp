#pragma once

#include <iostream>

using std::cout;
using std::endl;

class ClapTrap
{
	private:
		std::string name;
		int			health, energy, damage;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap&);
		ClapTrap& operator=(const ClapTrap&);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
