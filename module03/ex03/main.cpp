#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap firstDiamond("Odin");
	DiamondTrap secondDiamond(firstDiamond);
	DiamondTrap copyDiamond("");
	copyDiamond = firstDiamond;

	firstDiamond.attack("Thor");
	secondDiamond.takeDamage(500);
	secondDiamond.beRepaired(10);
	secondDiamond.highFivesGuys();
	return 0;
}