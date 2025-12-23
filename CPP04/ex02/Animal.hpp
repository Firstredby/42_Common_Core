#pragma once

#include <iostream>

using std::cout;
using std::endl;

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal(/* args */);
		AAnimal(const AAnimal&);
		AAnimal& operator=(const AAnimal&);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		const std::string getType() const;
};
