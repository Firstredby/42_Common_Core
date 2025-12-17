#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	cout << "WrongCat constructor called!\n";
}

WrongCat::WrongCat(const WrongCat& breed)
{
	cout << "WrongCat copy constructor called!\n";
	WrongCat::operator=(breed);
}

WrongCat& WrongCat::operator=(const WrongCat& breed)
{
	cout << "WrongCat copy assign constructor called!\n";
	if (this != &breed)
		this->type = breed.type;
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