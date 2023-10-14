#include "ScavTrap.hpp"

int main()
{
	ScavTrap st1("st1");
	ScavTrap st2("st2");

	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());

	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());

	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());

	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());

    st2.beRepaired(10);

	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());
	
	st1.attack("st2");
	st2.takeDamage(st1.getAttackDamage());

	return (0);
}
