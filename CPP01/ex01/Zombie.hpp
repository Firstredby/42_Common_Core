#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

#define cout std::cout
#define endl std::endl

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

Zombie* ZombieHorde(int N, std::string name);

#endif