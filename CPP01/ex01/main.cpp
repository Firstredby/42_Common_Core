#include "Zombie.hpp"

void	LeonKennedy(Zombie *horde)
{
	delete[] horde;
}

void	AdaWong(Zombie *zombie)
{
	delete zombie;
}

int main()
{
	Zombie	onezombie;
	onezombie.setName("LonelyWolf");
	onezombie.announce();
	cout << "================" << endl;
	Zombie	*anotherzombie = new Zombie;
	anotherzombie->setName("BraveCrawler");
	anotherzombie->announce();
	AdaWong(anotherzombie);
	cout << "================" << endl;
	Zombie	*horde = NULL;
	horde = ZombieHorde(5, "ZombieMeepo");
	LeonKennedy(horde);
	cout << "================" << endl;
	return 0;
}