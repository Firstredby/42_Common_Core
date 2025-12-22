#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const int defaultHealth = 100;
		static const int defaultEnergy = 100;
		static const int defaultDamage = 30;
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		void	highFivesGuys(void);
		void	beRepaired(unsigned int amount);
		void	attack(const std::string& target);
};


