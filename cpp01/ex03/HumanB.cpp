#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (!this->weapon)
        std::cout << this->name << " has not weapon" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}