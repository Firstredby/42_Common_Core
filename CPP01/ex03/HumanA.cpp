#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	cout << this->name << " appeared!" << endl;
}

HumanA::~HumanA()
{
	cout << "Rest in peace " << this->name << "..." << endl;
}

void	HumanA::attack()
{
	cout << this->name << " attacks with their "
		 << this->weapon.gettype() << endl;
}
