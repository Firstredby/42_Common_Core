#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

using std::cout;
using std::endl;

class Dog : public AAnimal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		void	makeSound() const;
		Brain&	getBrain();
};
