#include "Weapon.hpp"

std::string	Weapon::gettype()
{
	return this->type;
}

void	Weapon::settype(std::string type)
{
	this->type = type;
}

Weapon::Weapon(void)
{
	this->type = "Rock";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	cout << "No more violence for today" << endl;
}