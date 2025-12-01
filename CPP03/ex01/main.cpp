#include "ScavTrap.hpp"

int main()
{
	cout << "\n=== ClapTrap BASIC CONSTRUCTORS ===\n";
	ClapTrap c1;
	ClapTrap c2("Jimmy");

	cout << "\n=== ClapTrap ATTACK TESTS ===\n";
	c1.attack("Jimmy");
	c2.attack("ClapBob");

	cout << "\n=== ClapTrap DAMAGE / DEATH TESTS ===\n";
	c2.takeDamage(3);
	c2.takeDamage(7);
	c2.takeDamage(5);

	cout << "\n=== ClapTrap REPAIR TESTS ===\n";
	c1.takeDamage(1);
	c1.beRepaired(3);

	cout << "\n-- Repair at full health --\n";
	c1.beRepaired(5);

	cout << "\n-- Repair with 0 energy --\n";
	for (int i = 0; i < 7; i++)
		c1.attack("a dummy target");
	c1.beRepaired(2);

	cout << "\n=== ClapTrap DEATH REPAIR/ATTACK ===\n";
	ClapTrap dead("Ghost");
	dead.takeDamage(20);
	dead.attack("nobody");
	dead.beRepaired(10);

	cout << "\n=== ClapTrap ASSIGNMENT OPERATOR ===\n";
	ClapTrap copyA("CopyA");
	ClapTrap copyB("CopyB");

	copyA.takeDamage(4);
	copyB = copyA;
	copyB.attack("TestTarget");

	// ------------------------------------------------------------
	//                    SCAVTRAP TESTS
	// ------------------------------------------------------------

	cout << "\n\n====================================";
	cout << "\n=========== SCAVTRAP TESTS =========";
	cout << "\n====================================\n";

	cout << "\n=== ScavTrap BASIC CONSTRUCTORS ===\n";
	ScavTrap s1;
	ScavTrap s2("Guardian");

	cout << "\n=== ScavTrap ATTACK (inherited) ===\n";
	s1.attack("Bandit");

	cout << "\n=== ScavTrap DAMAGE / DEATH TESTS ===\n";
	s2.takeDamage(30);   // hp 70
	s2.takeDamage(60);   // hp 10
	s2.takeDamage(20);   // should die

	cout << "\n=== ScavTrap REPAIR TEST ===\n";
	s1.beRepaired(10);   // should work, energy--

	cout << "\n=== ScavTrap GUARD MODE ===\n";
	s1.guardGate();

	cout << "\n=== ScavTrap ASSIGNMENT OPERATOR ===\n";
	ScavTrap s3("CopySrc");
	ScavTrap s4("CopyDst");

	s3.takeDamage(15);
	s4 = s3;
	s4.attack("Enemy");

	cout << "\n\n========== [ HEAP ALLOCATION TESTS ] ==========\n";
	ClapTrap* hc = new ClapTrap("HeapClap");
	ScavTrap* hs = new ScavTrap("HeapScav");
	hc->attack("HeapTarget");
	hs->guardGate();
	delete hc;
	delete hs;
	cout << "\n=== END OF ALL TESTS ===\n\n";

	return 0;
}
