#include "Zombie.hpp"

int main()
{
    Zombie* zombies = zombieHorde(5, "xdd");
    for (int i = 0; i < 5; i++)
   
{
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}