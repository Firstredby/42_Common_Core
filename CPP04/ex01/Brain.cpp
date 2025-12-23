#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain constructor called!\n";
}

Brain::Brain(const Brain& brain)
{
	cout << "Brain copy constructor called!\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain)
{
	cout << "Brain copy assignment constructor called!\n";
	if (this != &brain)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	return *this;
}

Brain::~Brain()
{
	cout << "Brain destructor called!\n";
}

void	Brain::setIdea(size_t index, std::string idea)
{
	if (index >= 100)
	{
		cout << "already full of ideas!\n";
		return ;
	}
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(size_t idea) const
{
	if (idea >=100)
	{
		cout << "incorrect index!\n";
		return "";
	}
	return ideas[idea];
}