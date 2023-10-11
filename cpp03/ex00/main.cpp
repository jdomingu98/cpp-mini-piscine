#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct1("ct1");
    ClapTrap ct2 = ClapTrap();

    ct1.setAttackDamage(2);
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());

    ct2.setAttackDamage(10);
    ct2.attack(ct1.getName());
    ct1.takeDamage(ct2.getAttackDamage());
    ct2.attack(ct1.getName());
    for(int i = 0; i < 10; i++)
        ct2.beRepaired(1);
    return 0;
}
