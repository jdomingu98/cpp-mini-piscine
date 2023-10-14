#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& ct);
        ~ClapTrap();

        ClapTrap& operator = (const ClapTrap& f);

        std::string getName();
        unsigned int getAttackDamage();

        void setName(std::string name);
        void setAttackDamage(unsigned int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif