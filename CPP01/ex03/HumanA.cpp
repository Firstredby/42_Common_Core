#include "HumanA.hpp"

HumanA::HumanA()
{
	Weapon rock;
	this->name = "Caveman";
	this->weapon = rock;
}

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = weapon;
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
