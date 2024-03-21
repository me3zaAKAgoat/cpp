#pragma once

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include "Contact.hpp"


class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContacts();
	private:
		static int const MAX_CONTACTS = 8;
		Contact	contacts[MAX_CONTACTS];
		static int	contactCount;
};
