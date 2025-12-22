#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavRob")
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	cout << this->name << ": Behold, puny mortals! ScavTrap bursts onto the scene, "
		 << "loud, dramatic, and absolutely convinced you've been "
		 << "waiting for this moment!" << endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	cout << name << ": Behold, puny mortals! ScavTrap bursts onto the scene, "
		 << "loud, dramatic, and absolutely convinced you've been "
		 << "waiting for this moment!" << endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	cout << "ScavTrap copy constructor called!" << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	cout << "ScavTrap copy assignment constructor called!" << endl;
	if (this != &obj)
	{
		cout << this->name << ": Wait, what? I don't wanna cha.." << endl;
		ClapTrap::operator=(obj);
		cout  << this->name << ": Hello little fellas!" << endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << name << ": ScavTrap, master of dramatic exits, vanishes now. Try "
		 << "not to sob uncontrollably in my absence" << endl;
}

void	ScavTrap::attack(const std::string& target)
{
	
	if (this->energy > 0 && this->health > 0)
	{
		cout << "ScavTrap " << this->name << " attacks "
			 << target << ", causing " << damage
			 << " points of damage!" << endl;
		this->energy--;
	}
	else if (this->energy <= 0 && this->health > 0)
		cout << this->name << ": Oh sure, I'd love to attack that guy. Really, I would."
			 << " But I currently have the energy level of a dead toaster." << endl;
	else
		cout << this->name << ": I CAN'T ATTACK, OKAY?! I'm dead! Super-dead! Dramatically, "
			 << "heroically, award-winningly dead.\nSo stop poking me unless "
			 << "you want a ghostly guilt trip!" << endl;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->health < 100 && this->health > 0)
	{
		cout << "ScavTrap " << this->name << " repairing itself for "
			 << amount << " points!" << endl;
		this->health += amount;
		this->energy--;
	}
	else if (this->energy > 0 && this->health >= 100)
		cout << this->name << ": Great news! I tried to repair myself, but it turns "
			 << "out I'm already at maximum fabulousness! Uh, I mean HP." << endl
			 << "Any more healing and I might explode from perfection… "
			 << "and not the cool kind!" << endl;
	else if (this->energy == 0 && this->health > 0)
		cout << this->name << ": Oh absolutely, I'd love to repair myself, just let me grab some "
			 << "energy from the giant reserve of NOTHING I currently have." << endl;
	else
		cout << this->name << ": HEY! I was doing a perfectly convincing I'm-totally-dead performance "
				"here, and you RUINED IT!\nI can't repair myself — I HAVE NO HP, so let me suffer "
			 << "dramatically in peace!" << endl;
}

void	ScavTrap::guardGate()
{
	cout << this->name << " is guarding" << endl;
}