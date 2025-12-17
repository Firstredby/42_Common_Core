#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat constructor called!\n";
	this->type = "Cat";
	this->brain = new Brain;
	if (!this->brain)
	{
		std::cerr << "alloc error\n";
		this->brain = NULL;
		return ;
	}
}

Cat::Cat(const Cat& breed)
{
	cout << "Cat copy constructor called!\n";
	this->brain = new Brain;
	if (!this->brain)
	{
		std::cerr << "alloc error\n";
		this->brain = NULL;
		return ;
	}
	Cat::operator=(breed);
}

Cat& Cat::operator=(const Cat& breed)
{
	cout << "Cat copy assign constructor called!\n";
	if (this != &breed)
	{
		this->type = breed.type;
		for (int i = 0; !breed.brain->getIdea(i).empty(); i++)
			this->brain->setIdea(i, breed.brain->getIdea(i));
	}
	return *this;
}

Cat::~Cat()
{
	cout << "Cat destructor called!\n";
	if (this->brain)
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