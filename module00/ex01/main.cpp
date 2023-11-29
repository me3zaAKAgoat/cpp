#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

int main()
{
	PhoneBook phoneBook;
	std::string command = "";

	while (true)
	{
		std::cout << "Enter a command to interact with the phonebook: ";
		std::getline(std::cin, command);
	
		if (std::cin.eof())
			break ;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Command is invalid, enter one of: ADD, SEARCH, EXIT" << std::endl;
	}
	exit(0);
}