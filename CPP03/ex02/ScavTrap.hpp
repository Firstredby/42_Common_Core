#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
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
