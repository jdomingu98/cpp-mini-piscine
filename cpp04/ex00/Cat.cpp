#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& cat)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = cat.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Miiiauuuuuu" << std::endl;
}