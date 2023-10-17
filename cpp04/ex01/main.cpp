#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal *arr[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		delete arr[i];
	}

	return 0;
}