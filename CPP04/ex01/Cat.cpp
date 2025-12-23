#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat constructor called!\n";
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat& breed) : Animal(breed), brain(NULL)
{
	cout << "Cat copy constructor called!\n";
	this->brain = new Brain(*breed.brain);
}

Cat& Cat::operator=(const Cat& breed)
{
	cout << "Cat copy assign constructor called!\n";
	if (this != &breed)
	{
		Animal::operator=(breed);
		delete brain;
		brain = new Brain(*breed.brain);
	}
	return *this;
}

Cat::~Cat()
{
	cout << "Cat destructor called!\n";
	delete this->brain;
}

void	Cat::makeSound() const
{
	cout << "Meow!\n";
}

Brain&	Cat::getBrain()
{
	return *this->brain;
}