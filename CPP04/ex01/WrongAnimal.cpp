#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) : type(animal.type)
{
	cout << "WrongAnimal copy constructor called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
	cout << "WrongAnimal copy assign constructor called!\n";
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called!\n";
}

void	WrongAnimal::makeSound() const
{ 	
}

const std::string	WrongAnimal::getType() const
{
	return this->type;
}