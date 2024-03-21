#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( MateriaSource const & src );
		MateriaSource &		operator=( MateriaSource const & rhs );
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const &);
	private:
		AMateria* materia[4];
};