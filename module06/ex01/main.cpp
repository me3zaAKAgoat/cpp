#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *original = new Data;
	*original = (Data){.s1 = "Yo", .n = 1337, .s2 = "Hi"};

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "raw: " << raw << std::endl;

	Data *deserialized = Serializer::deserialize(raw);

	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "s1: " << original->s1 << std::endl;
	std::cout << "n: " << original->n << std::endl;
	std::cout << "s2: " << original->s2 << std::endl;

	delete original;
	return 0;
}