#include "Zombie.hpp"

int main(void)
{
    int n = 8;
    Zombie *horde = zombieHorde(n, "horde");
    for(int i = 0; i < n; i++)
        horde[i].announce();
    delete [] horde;
    return 0;
}