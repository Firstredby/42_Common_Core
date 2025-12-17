#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog constructor called!\n";
	this->type = "Dog";
	this->brain = new Brain;
	if (!this->brain)
	{
		std::cerr << "alloc error\n";
		this->brain = NULL;
		return ;
	}
}

Dog::Dog(const Dog& breed)
{
	cout << "Dog copy constructor called!\n";
	this->brain = new Brain;
	if (!this->brain)
	{
		std::cerr << "alloc error\n";
		this->brain = NULL;
		return ;
	}
	Dog::operator=(breed);
}

Dog& Dog::operator=(const Dog& breed)
{
	cout << "Dog copy assign constructor called!\n";
	if (this != &breed)
	{
		this->type = breed.type;
		for (int i = 0; !breed.brain->getIdea(i).empty(); i++)
			this->brain->setIdea(i, breed.brain->getIdea(i));
	}
	return *this;
}

Dog::~Dog()
{
	cout << "Dog destructor called!\n";
	if (this->brain)
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