#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Pedro");
    zombie->announce();
    delete zombie;
    randomChump("random");
    return 0;
}