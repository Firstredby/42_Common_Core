#include "DiamondTrap.hpp"

static void	printStats(const DiamondTrap& d, const std::string& label)
{
	std::cout << "[STATS] " << label << std::endl;
	std::cout << "  HP     = " << d.getHealthPoints() << std::endl;
	std::cout << "  Energy = " << d.getEnergyPoints() << std::endl;
	std::cout << "  Damage = " << d.getAttackDamage() << std::endl;
}


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
	//                    DiamondTrap TESTS
	//-------------------------------------------------------------
	cout << "\n\n========== [ DiamondTrap TESTS ] ==========\n";

	std::cout << "\n===== TEST 1: Default constructor stats =====" << std::endl;
	{
		DiamondTrap a;
		a.whoAmI();
		printStats(a, "Default DiamondTrap");
	}

	std::cout << "\n===== TEST 2: Named constructor stats =====" << std::endl;
	{
		DiamondTrap b("ShinyBoy");
		b.whoAmI();
		printStats(b, "Named DiamondTrap");
	}

	std::cout << "\n===== TEST 3: Copy constructor preserves stats =====" << std::endl;
	{
		DiamondTrap original("Original");
		original.takeDamage(25);
		original.beRepaired(10);

		DiamondTrap copy(original);
		printStats(copy, "Copy of Original");
	}

	std::cout << "\n===== TEST 4: Copy assignment preserves stats =====" << std::endl;
	{
		DiamondTrap a("Alpha");
		DiamondTrap b("Beta");

		a.takeDamage(40);
		b = a;

		printStats(b, "Assigned from Alpha");
	}

	std::cout << "\n===== TEST 5: Stat changes after actions =====" << std::endl;
	{
		DiamondTrap d("Fighter");

		printStats(d, "Before combat");
		d.attack("training dummy");
		printStats(d, "After attack");

		d.takeDamage(30);
		printStats(d, "After taking damage");

		d.beRepaired(20);
		printStats(d, "After repair");
	}

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
