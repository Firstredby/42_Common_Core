#include "ClapTrap.hpp"

int main()
{
	cout << "\n=== Creating ClapBob ===" << endl;
	ClapTrap a;

	cout << "\n=== Creating Jack ===" << endl;
	ClapTrap b("Jack");

	cout << "\n=== Attack test ===" << endl;
	a.attack("Jack");
	b.attack("ClapBob");

	cout << "\n=== Taking damage ===" << endl;
	b.takeDamage(3);
	b.takeDamage(8);

	cout << "\n=== Repair test (normal) ===" << endl;
	a.takeDamage(1);
	a.beRepaired(3);

	cout << "\n=== Repair with full HP ===" << endl;
	a.beRepaired(5);

	cout << "\n=== Energy depletion ===" << endl;
	for (int i = 0; i < 7; i++)
		a.attack("a random skag");

	cout << "\n=== Attempt repair with 0 energy ===" << endl;
	a.attack("a random skag");

	cout << "\n=== Simulated death test ===" << endl;
	ClapTrap c("DeadBot");

	cout << "(Manually setting health to 0 in test)" << endl;
	c.takeDamage(20);

	c.attack("anybody");
	c.beRepaired(5);

	cout << "\n=== Assignment operator ===" << endl;
	ClapTrap d("CopyDest");
	d = a;
	d.attack("Someone");

	cout << "\n\n========== [ HEAP ALLOCATION TESTS ] ==========\n";
	cout << "\n-- Single object --\n";
	ClapTrap* hc = new ClapTrap("HeapClap");
	hc->attack("HeapTarget");
	delete hc;

	cout << "\n-- Array of ClapTraps on heap --\n";
	ClapTrap* arr = new ClapTrap[3];

	arr[0].attack("A");
	arr[1].attack("B");
	arr[2].attack("C");

	delete[] arr;

	cout << "\n=== End of tests ===" << endl;
	return 0;
}
