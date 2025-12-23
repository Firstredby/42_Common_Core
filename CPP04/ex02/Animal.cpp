#include "Animal.hpp"

AAnimal::AAnimal()
{
	cout << "Animal constructor called!\n";
}

AAnimal::AAnimal(const AAnimal& animal) : type(animal.type)
{
	cout << "Animal copy constructor called!\n";
}

AAnimal& AAnimal::operator=(const AAnimal& animal)
{
	cout << "Animal copy assign constructor called!\n";
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

AAnimal::~AAnimal()
{
	cout << "Animal destructor called!\n";
}

void	AAnimal::makeSound() const
{
}

const std::string	AAnimal::getType() const
{
	return this->type;
}