#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const AAnimal *arr[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		delete arr[i];
	}

	std::cout << std::endl;

	Cat cat1;

	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
		cat1.getBrain()->setIdea(i, "idea");

	std::cout << std::endl;

	Cat cat2(cat1);

	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << cat2.getBrain()->getIdea(i) << std::endl;
	
	std::cout << std::endl;

	cat1.getBrain() == cat2.getBrain() ? std::cout << "Deep copy" : std::cout << "Shallow copy";

	std::cout << std::endl;

	return 0;
}