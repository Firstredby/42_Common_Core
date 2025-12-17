#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	cout << "Cat constructor called!\n";
}

Cat::Cat(const Cat& breed)
{
	cout << "Cat copy constructor called!\n";
	Cat::operator=(breed);
}

Cat& Cat::operator=(const Cat& breed)
{
	cout << "Cat copy assign constructor called!\n";
	if (this != &breed)
		this->type = breed.type;
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