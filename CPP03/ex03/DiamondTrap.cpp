#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
		: ClapTrap("BaoBab_clap_name"), ScavTrap(), FragTrap(), name("BaoBab")
{
	ClapTrap::health = FragTrap::defaultHealth;
	ClapTrap::energy = ScavTrap::defaultEnergy;
	ClapTrap::damage = FragTrap::defaultDamage;
	cout << this->name
		 << ": Witness perfection, mortals! A DiamondTrap descends upon you — "
		 << "shiny, deadly, and painfully aware of its own magnificence!" << endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
		: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	ClapTrap::health = FragTrap::defaultHealth;
	ClapTrap::energy = ScavTrap::defaultEnergy;
	ClapTrap::damage = FragTrap::defaultDamage;
	cout << this->name
		 << ": Witness perfection, mortals! A DiamondTrap descends upon you — "
		 << "shiny, deadly, and painfully aware of its own magnificence!" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
		: ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name(obj.name)
{
	cout << "DiamondTrap copy constructor called!" << endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	cout << "DiamondTrap copy assignment constructor called!" << endl;
	if (this != &obj)
	{
		cout << this->name
			 << ": Wait, hold on! Identity crisis incoming..." << endl;
		ClapTrap::operator=(obj);
		this->name = obj.name;
		cout << this->name
			 << ": Crisis resolved. I am still fabulous. Carry on." << endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	cout << this->name
		 << ": DiamondTrap disengaging. Try not to cry over my inevitable absence. "
		 << "I know I would." << endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
    if (ClapTrap::health > 0 && ClapTrap::health < 100 && ClapTrap::energy > 0)
    {
		ClapTrap::health += amount;
		ClapTrap::energy--;
		cout << this->name << ": I have magnificently restored " << amount
			 << " HP! Current health: " << ClapTrap::health
			 << ". Energy remaining: " << ClapTrap::energy << endl;
    }
    else if (ClapTrap::health >= 100)
        cout << this->name << ": Oh, I'm already at peak fabulousness!"
			 << " Any more healing and I might literally sparkle out of existence!" << endl;
    else if (ClapTrap::energy == 0 && ClapTrap::health > 0)
        cout << this->name << ": I would love to repair myself, truly. "
			 << "But alas, my energy reserves are as empty as a meatbag's logic." << endl;
    else
        cout << this->name << ": I'm quite dead. Your attempts at repairs are "
			 << "futile — but do try. It's entertaining." << endl;
}

void	DiamondTrap::whoAmI()
{
	cout << this->name << ": I have two names. " << this->name
		 << " for legends, " << ClapTrap::name
		 << " for legal paperwork." << endl
		 << this->name << ": Choose wisely." << endl;
}

int DiamondTrap::getHealthPoints() const
{
	return ClapTrap::health;
}

int DiamondTrap::getEnergyPoints() const
{
	return ClapTrap::energy;
}

int DiamondTrap::getAttackDamage() const
{
	return ClapTrap::damage;
}
