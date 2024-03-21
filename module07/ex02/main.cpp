#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 10
int main()
{
	Array<int> numbers(MAX_VAL);
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() / (RAND_MAX / 30);
		numbers[i] = value;
	}
	std::cout << "Array contains:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
	{
		Array<int> numbers_cpy(MAX_VAL);

		numbers_cpy = numbers;
		std::cout << "Array contains:" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << numbers_cpy[i] << std::endl;
		}
	}
	{
		Array<int> numbers_cpy(numbers);

		std::cout << "Array contains:" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << numbers_cpy[i] << std::endl;
		}
	}
	std::cout << "Trying to access out of range index" << std::endl;
	try
	{
		const int index = rand() % MAX_VAL;
		std::cout << "Index: " << index << std::endl;
		std::cout << "Value: " << numbers[index] << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}