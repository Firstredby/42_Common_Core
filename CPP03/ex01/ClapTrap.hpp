#pragma once

#include <iostream>

using std::cout;
using std::endl;

class ClapTrap
{
	protected:
		const std::string name;
		int	health, energy, damage;
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap& operator=(const ClapTrap&);
		virtual ~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};
