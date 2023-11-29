#include "FragTrap.hpp"

int main()
{
	FragTrap firstFrag("Odin");
	FragTrap secondFrag(firstFrag);
	FragTrap copyFrag("");
	copyFrag = firstFrag;

	firstFrag.attack("Thor");
	secondFrag.takeDamage(500);
	secondFrag.beRepaired(10);
	secondFrag.highFivesGuys();
	return 0;
}