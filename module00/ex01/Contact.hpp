#pragma once

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <string>

class Contact
{
	public :
		Contact();
		~Contact();
		void		populate();
		void		displayFull() const;
		void		displaySnippet() const;
	private:
		std::string	populateField(std::string msg) const;
		std::string	handleTruncation(const std::string& str) const;
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
};
