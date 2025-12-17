#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== BASIC POLYMORPHISM TEST =====" << std::endl;

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

	/* ------------------------------------------------------------ */

	std::cout << "\n===== WRONG POLYMORPHISM TEST =====" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	std::cout << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();

	delete wrongCat;
	delete wrongAnimal;

	/* ------------------------------------------------------------ */

	std::cout << "\n===== ANIMAL ARRAY TEST =====" << std::endl;

	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- Deleting animals via Animal* ---" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		delete animals[i];
	}

	/* ------------------------------------------------------------ */

	std::cout << "\n===== DEEP COPY TEST (DOG) =====" << std::endl;

	Dog originalDog;
	originalDog.getBrain().setIdea(0, "Protect the house");
	originalDog.getBrain().setIdea(1, "Chase the cat");

	Dog copiedDog(originalDog);

	std::cout << "Original Dog idea[0]: "
			  << originalDog.getBrain().getIdea(0) << std::endl;
	std::cout << "Copied Dog idea[0]:   "
			  << copiedDog.getBrain().getIdea(0) << std::endl;

	originalDog.getBrain().setIdea(0, "Eat food");

	std::cout << "\nAfter modifying original:" << std::endl;
	std::cout << "Original Dog idea[0]: "
			  << originalDog.getBrain().getIdea(0) << std::endl;
	std::cout << "Copied Dog idea[0]:   "
			  << copiedDog.getBrain().getIdea(0) << std::endl;

	/* ------------------------------------------------------------ */

	std::cout << "\n===== DEEP COPY TEST (CAT) =====" << std::endl;

	Cat originalCat;
	originalCat.getBrain().setIdea(0, "Sleep on keyboard");

	Cat copiedCat;
	copiedCat = originalCat;

	std::cout << "Original Cat idea[0]: "
			  << originalCat.getBrain().getIdea(0) << std::endl;
	std::cout << "Copied Cat idea[0]:   "
			  << copiedCat.getBrain().getIdea(0) << std::endl;

	originalCat.getBrain().setIdea(0, "Knock glass off table");

	std::cout << "\nAfter modifying original:" << std::endl;
	std::cout << "Original Cat idea[0]: "
			  << originalCat.getBrain().getIdea(0) << std::endl;
	std::cout << "Copied Cat idea[0]:   "
			  << copiedCat.getBrain().getIdea(0) << std::endl;

	/* ------------------------------------------------------------ */

	std::cout << "\n===== END OF PROGRAM =====" << std::endl;
	std::cout << "Run with valgrind to verify no memory leaks." << std::endl;

	return 0;
}
