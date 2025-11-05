#include "Zombie.hpp"

int main()
{
	Zombie	zombie1;
	zombie1.announce();
	cout << "================" << endl;
	Zombie	zombie2;
	zombie2.setName("Alyosha");
	zombie2.announce();
	cout << "================" << endl;
	Zombie*	zombie3 = NULL;
	zombie3 = newZombie("Kenny");
	if (!zombie3) 
	{
		cout << "malloc error" << endl;
		return 1;
	}
	zombie3->announce();
	cout << "================" << endl;
	randomChump("Buzzlighter");
	cout << "================" << endl;
	Zombie*	zombie4 = new Zombie();
	if (!zombie4)
	{
		cout << "malloc error" << endl;
		return 1;
	}
	zombie4->setName("Goofy");
	zombie4->announce();
	cout << "================" << endl;
	delete(zombie3);
	delete(zombie4);
	return 0;
}