#include "PmergeMe.hpp"

bool	isValidInt(std::string const &s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (i == 0 && s[i] == '+')
			continue; 
		if ((i == 0 && s[i] == '-') || !std::isdigit(s[i]))
			return false;
	}
	return true;
}

int main(int ac, char **av)
{
	try {
		std::vector<int> uniquesList;

		if (ac < 2)
			throw std::runtime_error("Error: No input");
		for (int i = 1; i < ac; i++)
		{
			if (!isValidInt(av[i]))
				throw std::runtime_error("Error: Not a valid integer");
			if (std::find(uniquesList.begin(), uniquesList.end(), std::atoi(av[i])) != uniquesList.end())
				continue;
			uniquesList.push_back(std::atoi(av[i]));
		}
		PmergeMe a("list", uniquesList);
		PmergeMe b("deque", uniquesList);
		std ::cout << "Before: ";
		a.print();
		a.sort();
		b.sort();
		std ::cout << "After: ";
		a.print();
		return 0;
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}