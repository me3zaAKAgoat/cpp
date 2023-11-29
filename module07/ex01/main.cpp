#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    return (0);
}