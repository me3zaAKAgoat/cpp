#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void leaks()
{
	system("leaks exec");
}
int main()
{
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	src->learnMateria(ice);
	Cure *cure = new Cure();
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	delete ice;
	delete cure;
	delete bob;
	delete me;
	delete src;
	return (0);
}