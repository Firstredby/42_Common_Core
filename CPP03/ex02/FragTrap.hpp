#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		void	highFivesGuys(void);
		void	beRepaired(unsigned int amount);
};


