#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> l;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	try
	{
		std::cout << easyfind(l, 5) << std::endl;
		std::cout << easyfind(l, 5) << std::endl;
		std::cout << easyfind(d, 5) << std::endl;
		std::cout << easyfind(l, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}