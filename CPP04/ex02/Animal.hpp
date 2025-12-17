#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Animal
{
	protected:
		std::string type;
	public:
		Animal(/* args */);
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		const std::string getType() const;
};
