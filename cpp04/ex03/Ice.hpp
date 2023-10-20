#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &ice);
        virtual ~Ice();

        Ice& operator=(const Ice &ice);

        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif