#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "----- Testing Animals -----" << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << animal->getType() << std::endl;
	animal->makeSound();

	delete cat;
	delete dog;
	delete animal;

	std::cout << "\n----- Testing Copy & Assignment -----" << std::endl;

	Cat cat1;
	cat1.makeSound();

	Cat cat2(cat1);
	cat2.makeSound();

	Cat cat3;
	cat3 = cat1;
	cat3.makeSound();

	std::cout << "\n----- Testing Polymorphic Copy -----" << std::endl;
	Animal* a1 = new Cat();
	Animal* a2 = new Dog();
	*a2 = *a1;
	a2->makeSound();
	delete a1;
	delete a2;

	std::cout << "\n----- Testing Wrong Animals -----" << std::endl;
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << std::endl;
	wrongcat->makeSound();
	std::cout << wronganimal->getType() << std::endl;
	wronganimal->makeSound();

	delete wrongcat;
	delete wronganimal;
	
	std::cout << "\n----- WrongCat memory test -----" << std::endl;
	WrongCat wc1;

	return 0;
}