#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie * newzombie = new Zombie;
	newzombie->setName(name);
	return (newzombie);
}