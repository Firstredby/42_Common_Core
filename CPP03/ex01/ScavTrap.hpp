#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	guardGate();
};
