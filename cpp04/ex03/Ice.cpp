#include"Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
    // std::cout << " Ice copy constructor called" << std::endl;
    *this = ice; 
}

Ice::~Ice()
{
    // std::cout<< "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice & ice)
{
    // std::cout << "Ice assignation operator called" << std::endl;
    this->type = ice.type;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice();
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}