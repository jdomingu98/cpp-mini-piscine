#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	
	const WrongAnimal* wc = new WrongCat();

	std::cout << std::endl;

	std::cout << wc->getType() << " " << std::endl;
	
	std::cout << std::endl;

	wc->makeSound();

	std::cout << std::endl;
	
	delete wc;

	return 0;
}