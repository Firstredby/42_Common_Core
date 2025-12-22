#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const int defaultHealth = 100;
		static const int defaultEnergy = 50;
		static const int defaultDamage = 20;
	public:
		ScavTrap();
		ScavTrap(const std::string&);
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();
		void	beRepaired(unsigned int amount);
		void	attack(const std::string& target);
		void	guardGate();
};
