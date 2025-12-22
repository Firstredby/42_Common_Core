#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("ChopTrap")
{
	this->health = 100;
	this->damage = 30;
	this->energy = 100;
	cout << this->name << ": Make way, boom-loving bystanders! FragTrap has arrived, "
		 << "and the party just got 300% more explosive!" << endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->health = 100;
	this->damage = 30;
	this->energy = 100;
	cout << this->name << ": Make way, boom-loving bystanders! FragTrap has arrived, "
		 << "and the party just got 300% more explosive!" << endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	cout << "FragTrap copy constructor called!" << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	cout << "FragTrap copy assignment operator called!" << endl;
	if (this != &obj)
	{
		cout << this->name << ": Wait, what? I don't wanna cha.." << endl;
		ClapTrap::operator=(obj);
		cout  << this->name << ": Hello little fellas!" << endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	cout << this->name << ": FragTrap is making his grand exit! Try not to blow "
		 << "anything up while I'm gone… or at least save the big booms for my "
		 << "return!" << endl;
}

void	FragTrap::highFivesGuys(void)
{
	cout << this->name << ": Hey! FragTrap here! Mind giving me a high five? C'mon, don't "
		 << "leave a bot hanging!" << endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->health > 0)
	{
		cout << "FragTrap " << this->name << " attacks "
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

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->health < 100 && this->health > 0)
	{
		cout << "FragTrap " << this->name << " repairing itself for "
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