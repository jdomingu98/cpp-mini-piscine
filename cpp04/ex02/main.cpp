#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"

int main(void) {
	const AAnimal *arr[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
		delete arr[i];

	return 0;
}