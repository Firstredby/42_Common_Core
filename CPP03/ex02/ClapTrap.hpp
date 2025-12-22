#pragma once

#include <iostream>

using std::cout;
using std::endl;

class ClapTrap
{
	protected:
		std::string name;
		int	health, energy, damage;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap&);
		ClapTrap& operator=(const ClapTrap&);
		virtual	~ClapTrap();
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};
