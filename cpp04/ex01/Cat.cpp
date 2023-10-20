#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    if (this->brain)
        delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& cat)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*(cat.brain));
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Miiiauuuuuu" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}