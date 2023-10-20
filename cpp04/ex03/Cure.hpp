#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &cure);
        virtual ~Cure();

        Cure& operator=(const Cure &cure);
        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif