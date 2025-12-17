#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	~Cat();
	void	makeSound() const;
	Brain&	getBrain();
};
