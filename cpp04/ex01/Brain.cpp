#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "";
    }
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& brain)
{
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}

void Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}
