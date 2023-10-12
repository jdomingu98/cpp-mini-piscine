#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{  
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& st);
        ~ScavTrap();

        ScavTrap& operator = (const ScavTrap& st);

        void attack(const std::string& target);
        void guardGate();
};

#endif