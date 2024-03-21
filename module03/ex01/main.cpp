#include "ScavTrap.hpp"

int main()
{
	ScavTrap firstScav("Odin");
	ScavTrap secondScav(firstScav);
	ScavTrap copyScav("");
	copyScav = firstScav;

	firstScav.attack("Thor");
	secondScav.takeDamage(500);
	secondScav.beRepaired(10);
	secondScav.guardGate();
	return 0;
}