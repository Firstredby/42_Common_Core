#pragma once

#include <iostream>

using std::cout;
using std::endl;

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=(const WrongAnimal&);
	virtual ~WrongAnimal();
	void makeSound() const;
	const std::string getType() const;
};
