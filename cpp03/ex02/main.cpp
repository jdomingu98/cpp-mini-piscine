#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap ft1("ft1");
	FragTrap ft2("ft2");
	ScavTrap st1("st1");
	ScavTrap st2("st2");

	ft1.beRepaired(10);
	ft1.attack("ft2");
	ft2.takeDamage(ft1.getAttackDamage());
    ft1.attack("ft2");
	ft2.takeDamage(ft1.getAttackDamage());
    ft1.attack("st1");
	st1.takeDamage(ft1.getAttackDamage());
    st1.attack("ft2");
	ft2.takeDamage(st1.getAttackDamage());
    ft1.attack("st2");
	st2.takeDamage(ft1.getAttackDamage());
    ft1.attack("ft2");
	ft2.beRepaired(10);
    return 0;
}