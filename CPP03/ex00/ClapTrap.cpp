#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapBob"), health(10), energy(10), damage(0)
{
	cout << this->name << ": Behold, meatbags! CL4P-TP has arrived, dramatically and"
		 << " uninvited, just the way you love it!" << endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), health(10), energy(10), damage(0)
{
	cout << this->name << ": Behold, meatbags! CL4P-TP has arrived, dramatically and"
		 << " uninvited, just the way you love it!" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->health = obj.health;
	this->damage = obj.damage;
	this->energy = obj.energy;
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << this->name << ": CL4P-TP is disappearing now. Try not to miss me too "
		 << "much, but I know it'll be hard!" << endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->health > 0)
	{
		cout << "ClapTrap " << this->name << " attacks "
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
void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < 0 || amount > 2147483647)
		cout << this->name << ": i've got HOW MUCH DAMAGE? No, no, no, i don't play like this!\n";
	else if (this->health > 0)
	{
		this->health -= amount;
		if (this->health > 0)
			cout << this->name << " was just BONK'ed for " << amount
				<< " damage!" << endl;
		else
			cout << this->name << " was ground in ashes after taking "
				 << amount << " damage!" << endl;
	}
	else
		cout << "The remnants of " << this->name << " received "
			 << amount << " damage!" << endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)amount < 0 || amount > 2147483647)
		cout << this->name << ": Where did you get this numbers?\n";
	if (this->energy > 0 && this->health < 10 && this->health > 0)
	{
		cout << "ClapTrap " << this->name << " repairing itself for "
			 << amount << " points!" << endl;
		this->energy--;
	}
	else if (this->energy > 0 && this->health >= 10)
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