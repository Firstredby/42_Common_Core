#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	//-------------------------------------------------------------
	//                    CLAPTRAP TESTS
	//-------------------------------------------------------------
	cout << "\n\n========== [ CLAPTRAP TESTS ] ==========\n";

	cout << "\n-- Constructors --\n";
	ClapTrap c1;
	ClapTrap c2("Jimmy");

	cout << "\n-- Attacking --\n";
	c1.attack("Jimmy");
	c2.attack("ClapBob");

	cout << "\n-- Damage + Death --\n";
	c2.takeDamage(3);
	c2.takeDamage(7);
	c2.takeDamage(5);

	cout << "\n-- Repairs --\n";
	c1.beRepaired(3);
	c1.takeDamage(1);
	c1.beRepaired(10);

	cout << "\n-- Energy depletion --\n";
	for (int i = 0; i < 9; i++)
		c1.attack("dummy");
	c1.beRepaired(2);

	cout << "\n-- Dead ClapTrap actions --\n";
	ClapTrap ghost("Ghost");
	ghost.takeDamage(50);
	ghost.attack("nobody");
	ghost.beRepaired(10);

	cout << "\n-- Assignment operator --\n";
	ClapTrap ca("Source");
	ClapTrap cb("Receiver");
	ca.takeDamage(5);
	cb = ca;
	cb.attack("Target");

	//-------------------------------------------------------------
	//                    SCAVTRAP TESTS
	//-------------------------------------------------------------
	cout << "\n\n========== [ SCAVTRAP TESTS ] ==========\n";

	cout << "\n-- Constructors --\n";
	ScavTrap s1;
	ScavTrap s2("Gatekeeper");

	cout << "\n-- Attacking --\n";
	s1.attack("Bandit");

	cout << "\n-- Damage + Death --\n";
	s2.takeDamage(30);
	s2.takeDamage(60);
	s2.takeDamage(20);

	cout << "\n-- Repairs --\n";
	s1.takeDamage(10);
	s1.beRepaired(10);
	s1.beRepaired(100);

	cout << "\n-- Energy depletion --\n";
	for (int i = 0; i < 48; i++)
		s1.attack("dummy");
	s1.beRepaired(5);

	cout << "\n-- Unique ability: guardGate() --\n";
	s1.guardGate();

	cout << "\n-- Assignment operator --\n";
	ScavTrap sA("Original");
	ScavTrap sB("CopyDest");
	sA.takeDamage(20);
	sB = sA;
	sB.attack("Enemy");

	//-------------------------------------------------------------
	//                    FRAGTRAP TESTS
	//-------------------------------------------------------------
	cout << "\n\n========== [ FRAGTRAP TESTS ] ==========\n";

	cout << "\n-- Constructors --\n";
	FragTrap f1;
	FragTrap f2("Boomer");

	cout << "\n-- Attacking --\n";
	f1.attack("Thug");

	cout << "\n-- Damage + Death --\n";
	f2.takeDamage(30);
	f2.takeDamage(40);
	f2.takeDamage(40);   // dead

	cout << "\n-- Repairs --\n";
	f1.takeDamage(20);
	f1.beRepaired(20);
	f1.beRepaired(200); // full HP

	cout << "\n-- Unique ability: highFivesGuys() --\n";
	f1.highFivesGuys();

	cout << "\n-- Assignment operator --\n";
	FragTrap fA("FragSrc");
	FragTrap fB("FragDst");
	fA.takeDamage(15);
	fB = fA;
	fB.attack("Arena target");


	//-------------------------------------------------------------
	//                HEAP ALLOCATION TESTS
	//-------------------------------------------------------------
	cout << "\n\n========== [ HEAP ALLOCATION TESTS ] ==========\n";

	cout << "\n-- Single objects --\n";
	ClapTrap* hc = new ClapTrap("HeapClap");
	ScavTrap* hs = new ScavTrap("HeapScav");
	FragTrap* hf = new FragTrap("HeapFrag");

	hc->attack("HeapTarget");
	hs->guardGate();
	hf->highFivesGuys();

	delete hc;
	delete hs;
	delete hf;

	cout << "\n\n========== [ END OF ALL TESTS ] ==========\n\n";

	return 0;
}
