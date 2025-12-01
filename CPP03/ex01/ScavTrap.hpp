#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();
		void	beRepaired(unsigned int amount);
		void	guardGate();
};
