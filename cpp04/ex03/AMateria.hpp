#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        ICharacter* target;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & amateria);
        virtual ~AMateria();
        AMateria & operator=(AMateria const & amateria);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif