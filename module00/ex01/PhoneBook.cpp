#include "PhoneBook.hpp"

int PhoneBook::contactCount = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	Contact newContact;

	newContact.populate();
	contacts[PhoneBook::contactCount % MAX_CONTACTS] = newContact;
	PhoneBook::contactCount++;
	std::cout << "Contact saved." << std::endl;
}


void	PhoneBook::searchContacts()
{
	if (PhoneBook::contactCount == 0)
	{
		std::cout << "Phone Book is empty." << std::endl;
		return;
	}

	const int arrayUpperBound = (PhoneBook::contactCount > MAX_CONTACTS ? MAX_CONTACTS : PhoneBook::contactCount);

	for (int i = 0; i < arrayUpperBound; i++)
	{
		std::cout << std::right << std::setw(10) << i << " | ";
		contacts[i].displaySnippet();
	}

	int	expandIndex;
	std::cout << "Enter the index of the contact you wish to expand: " << std::flush;
	while (true)
	{
		std::cin >> expandIndex;
		if (std::cin.eof())
			exit(1);
		if (std::cin.good() && (expandIndex < arrayUpperBound && expandIndex >= 0))
			break ;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Retry entering an integer that is not out of range." << std::endl;
		}
		std::cout << "Enter the index of the contact you wish to expand: " << std::flush;
	}
	contacts[expandIndex].displayFull();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}