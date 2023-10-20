#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = materiaSource;
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i])
        { 
            delete this->materias[i];
            this->materias[i]->clone();
        }
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i]) 
            delete this->materias[i];
    }
    // std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiaSource)
{
    // std::cout << "MateriaSource assignation operator called" << std::endl;
    *this = materiaSource;
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i])
        { 
            delete this->materias[i];
            this->materias[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = -1;
    while( ++i < 4 && this->materias[i]);
    i < 4 ? this->materias[i] = m : NULL;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = -1;
    while( ++i < 4 && this->materias[i])
    {
        if(this->materias[i] && this->materias[i]->getType() == type)
            return this->materias[i]->clone();
    }
    return NULL;
}
