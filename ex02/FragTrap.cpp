#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& ft) : ClapTrap(ft)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& ft)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    this->name = ft.name;
    this->hitPoints = ft.hitPoints;
    this->energyPoints = ft.energyPoints;
    this->attackDamage = ft.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " high fives guys" << std::endl;
}