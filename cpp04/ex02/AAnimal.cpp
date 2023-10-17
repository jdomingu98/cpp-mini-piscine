#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl;
    this->type = "";
}

AAnimal::AAnimal(const AAnimal& aanimal)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = aanimal;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& aanimal)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    this->type = aanimal.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal sound" << std::endl;
}