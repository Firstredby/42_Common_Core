#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog constructor called!\n";
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog& breed) : Animal(breed), brain(NULL)
{
	cout << "Dog copy constructor called!\n";
	this->brain = new Brain(*breed.brain);
}

Dog& Dog::operator=(const Dog& breed)
{
	cout << "Dog copy assign constructor called!\n";
	if (this != &breed)
	{
		Animal::operator=(breed);
		delete brain;
		brain = new Brain(*breed.brain);
	}
	return *this;
}

Dog::~Dog()
{
	cout << "Dog destructor called!\n";
	delete this->brain;
}

void	Dog::makeSound() const
{
	cout << "Bark!\n";
}

Brain&	Dog::getBrain()
{
	return *this->brain;
}