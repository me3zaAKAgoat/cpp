#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	// Animal *animal[10];

	// for (int i = 0; i < 5; i++)
	//
	// 	animal[i] = new Dog();
	// }

	// for (int i = 5; i < 10; i++)
	//
	// 	animal[i] = new Dog();
	// }

	// for (int i = 5; i < 10; i++)
	//
	// 	*animal[i] = *animal[i - 5];
	// }

	// for (int i = 0; i < 10; i++)
	//
	// 	delete animal[i];
	// }
	Animal *animal[10];
	
	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
	}

	for (int i = 5; i < 10; i++)
	{
		animal[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
	}

}