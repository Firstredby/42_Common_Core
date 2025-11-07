#include "Weapon.hpp"

const std::string&	Weapon::gettype() const
{
	return this->type;
}

void	Weapon::setType(std::string type)
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