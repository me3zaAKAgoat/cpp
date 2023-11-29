#include "ClapTrap.hpp"

int main()
{
    ClapTrap xd("CT");
    ClapTrap xdCopy(xd);
    ClapTrap xdAssign("");
    xdAssign = xd;

    xd.attack("civilians");
    xd.beRepaired(20);
    xd.takeDamage(9);
}