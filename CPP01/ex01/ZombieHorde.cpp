#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int j = 0; j < N; j++)
	{
		horde[j].setName(name);
		horde[j].announce();
	}
	cout << "Horde of " << N << " entities has been created" << endl;
	return horde;
}