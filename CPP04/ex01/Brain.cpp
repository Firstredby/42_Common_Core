#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain constructor called!\n";
}

Brain::Brain(const Brain& brain)
{
	cout << "Brain copy constructor called!\n";
	Brain::operator=(brain);
}

Brain& Brain::operator=(const Brain& brain)
{
	cout << "Brain copy assigment constructor called!\n";
	if (this != &brain)
		for (int i = 0; !ideas[i].empty(); i++)
			this->ideas[i] = brain.ideas[i];
	return *this;
}

Brain::~Brain()
{
	cout << "Brain destructor called!\n";
}

void	Brain::setIdea(size_t index, std::string idea)
{
	while (index >= 100)
		index -= 100;
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(size_t idea) const
{
	return ideas[idea];
}