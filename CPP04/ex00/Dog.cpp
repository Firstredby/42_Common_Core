#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog constructor called!\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& breed)
{
	cout << "Dog copy constructor called!\n";
	Dog::operator=(breed);
}

Dog& Dog::operator=(const Dog& breed)
{
	cout << "Dog copy assign constructor called!\n";
	if (this != &breed)
		this->type = breed.type;
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