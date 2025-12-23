#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	cout << "WrongCat constructor called!\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& breed) : WrongAnimal(breed)
{
	cout << "WrongCat copy constructor called!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& breed)
{
	cout << "WrongCat copy assign constructor called!\n";
	if (this != &breed)
		WrongAnimal::operator=(breed);
	return *this;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called!\n";
}

void	WrongCat::makeSound() const
{
	cout << "SHHH!\n";
}