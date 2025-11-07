#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main()
// {
//     Weapon* weapon = new Weapon;
// 	HumanA a("Bob", weapon);
//     HumanB b("Kenny");

//     a.attack();
//     b.attack();
//     cout << "======================" << endl;
//     weapon->settype("stick");
//     b.setweapon(weapon);

//     a.attack();
//     b.attack();
//     cout << "======================" << endl;
//     delete weapon;
// 	cout << "======================" << endl;
// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}