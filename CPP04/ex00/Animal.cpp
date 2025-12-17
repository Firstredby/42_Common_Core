#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal constructor called!\n";
}

Animal::Animal(const Animal& animal)
{
	cout << "Animal copy constructor called!\n";
	Animal::operator=(animal);
}

Animal& Animal::operator=(const Animal& animal)
{
	cout << "Animal copy assign constructor called!\n";
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

Animal::~Animal()
{
	cout << "Animal destructor called!\n";
}

void	Animal::makeSound() const
{
}

const std::string	Animal::getType() const
{
	return this->type;
}