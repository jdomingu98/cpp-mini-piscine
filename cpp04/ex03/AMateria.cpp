
#include"AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria default constructor called" << std::endl;
    this->type = "default"; 
}

AMateria::AMateria(std::string const & type)
{
    // std::cout << "AMateria type constructor called" << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria & aMateria)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = aMateria; 
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria & aMateria)
{
    // std::cout << "AMateria assignation operator called" << std::endl;
    this->type = aMateria.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "It was used the AMateria type " << type << " against " << target.getName() << std::endl;
}