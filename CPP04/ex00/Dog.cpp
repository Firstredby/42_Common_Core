#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog constructor called!\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& breed) : Animal(breed)
{
	cout << "Dog copy constructor called!\n";
}

Dog& Dog::operator=(const Dog& breed)
{
	cout << "Dog copy assign constructor called!\n";
	if (this != &breed)
		Animal::operator=(breed);
	return *this;
}

Dog::~Dog()
{
	cout << "Dog destructor called!\n";
}

void	Dog::makeSound() const
{
	cout << "Bark!\n";
}