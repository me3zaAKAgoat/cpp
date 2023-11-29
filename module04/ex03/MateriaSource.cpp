#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "Constructed MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	std::cout<< "Copy constructor MateriaSource" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destroyed MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->materia[i];
}

MateriaSource &		MateriaSource::operator=( MateriaSource const & rhs )
{
	std::cout << "Assignment operator MateriaSource" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			delete this->materia[i];
		for (int i = 0; i < 4; i++)
			if (rhs.materia[i])
				this->materia[i] = rhs.materia[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (!this->materia[i])
		{
			this->materia[i] = m->clone();
			return ;
		}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->materia[i] && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	return (NULL);
}