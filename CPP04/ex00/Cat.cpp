#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat constructor called!\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& breed) : Animal(breed)
{
	cout << "Cat copy constructor called!\n";
}

Cat& Cat::operator=(const Cat& breed)
{
	cout << "Cat copy assign constructor called!\n";
	if (this != &breed)
		Animal::operator=(breed);
	return *this;
}

Cat::~Cat()
{
	cout << "Cat destructor called!\n";
}

void	Cat::makeSound() const
{
	cout << "Meow!\n";
}