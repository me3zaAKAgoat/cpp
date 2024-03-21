#include "Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::populate()
{
	firstName = Contact::populateField("- Enter the contact's First Name: ");	
	lastName = Contact::populateField("- Enter the contact's Last Name: ");
	nickname = Contact::populateField("- Enter the contact's Nickname: ");
	phoneNumber = Contact::populateField("- Enter the contact's Phonenumber: ");
	darkestSecret = Contact::populateField("- Enter the contact's Darkest Secret: ");
}

std::string	Contact::populateField(std::string msg) const
{
	std::string value = "";

	std::cout << msg << std::flush;
	while (1)
	{
		std::getline(std::cin, value);
		if (std::cin.eof())
			exit(1);
		if (!value.empty() && std::cin.good())
			return (value);
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Retry entering a valid string." << std::endl;
		}
		std::cout << msg << std::flush;
	}
}

void	Contact::displayFull() const
{
	std::cout << "First Name:" << firstName << std::endl;
	std::cout << "Last Name:" << lastName << std::endl;
	std::cout << "Nickname:" << nickname << std::endl;
	std::cout << "Phone Number:" << phoneNumber << std::endl;
	std::cout << "Darkest Secret:" << darkestSecret << std::endl;
}

std::string	Contact::handleTruncation(const std::string& str) const
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str.substr(0, 10));
}

void	Contact::displaySnippet() const
{
	std::cout << std::right << std::setw(10) << handleTruncation(firstName) << " | ";
	std::cout << std::right << std::setw(10) << handleTruncation(lastName) << " | ";
	std::cout << std::right << std::setw(10) << handleTruncation(nickname) << std::endl;
}