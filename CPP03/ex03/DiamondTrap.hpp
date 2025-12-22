#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
		DiamondTrap();
		DiamondTrap(const std::string&);
		DiamondTrap(const DiamondTrap&);
		DiamondTrap& operator=(const DiamondTrap&);
		~DiamondTrap();

		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void whoAmI();

		int getHealthPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
};
