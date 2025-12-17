#pragma once

#include <iostream>
#include "Animal.hpp"

using std::cout;
using std::endl;

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		void	makeSound() const;
};
