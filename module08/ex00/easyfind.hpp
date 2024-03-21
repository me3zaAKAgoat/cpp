#pragma once

#include <exception>
#include <algorithm>

template <typename T>
int easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	else
		throw std::exception();
}