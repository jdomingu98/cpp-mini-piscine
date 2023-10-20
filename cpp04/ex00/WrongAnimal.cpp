#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    this->type = wrongAnimal.type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}