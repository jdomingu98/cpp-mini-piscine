#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {

    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA();
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();

        void attack();
};

#endif