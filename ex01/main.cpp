#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	Data *ptr = new Data;

	uintptr_t serialized = Serializer::serialize(ptr);

	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Comparing deserialized() equals to original pointer ptr" << std::endl; 
	std::cout << std::setw(14) << "Deserialized: " << deserialized << std::endl;
	std::cout << std::setw(14) << "Original: " << ptr << std::endl;

	delete ptr;
}