#include "HumanB.hpp"
#include <iostream>

void HumanB::attack()
{
    if (this->weapon == NULL)
        std::cout << this->name << " attacks with his bare hands" << std::endl;
    else
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}