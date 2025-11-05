#include "Zombie.hpp"


Zombie::Zombie(void)
{
	this->name = "Brainsucker";
}

Zombie::~Zombie(void)
{
	cout << Zombie::name << " is destroyed." << endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << endl;
}