#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	cout << this->name << " is appeared!" << endl;
}

HumanB::~HumanB()
{
	cout << "Rest in peace " << this->name << "..." << endl;
}

void	HumanB::attack() 
{
    if (this->weapon)
	    cout << this->name << " attacks with their "
		     << this->weapon->gettype() << endl;
    else
        cout << this->name << " attacks with their hands" << endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}