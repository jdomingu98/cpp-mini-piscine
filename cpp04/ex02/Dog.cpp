#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : AAnimal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator = (const Dog& dog)
{
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = dog.type;
    this->brain = dog.brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}