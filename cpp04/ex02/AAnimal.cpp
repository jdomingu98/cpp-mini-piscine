#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl;
    this->type = "";
}

AAnimal::AAnimal(const AAnimal& aAnimal)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = aAnimal;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& aAnimal)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    this->type = aAnimal.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}