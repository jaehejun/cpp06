#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	Data *ptr = new Data;
	
	ptr->cPtr = new char[100];
	for (int i = 0; i < 100; i++)
		ptr->cPtr[i] = 'a';
	ptr->character = 'b';
	ptr->number = 10;

	uintptr_t serialized = Serializer::serialize(ptr);
	std::cout << "ptr value in Demical: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Comparing deserialized() equals to original pointer ptr" << std::endl; 
	std::cout << std::setw(14) << "Deserialized: " << deserialized << std::endl;
	std::cout << std::setw(14) << "Original: " << ptr << std::endl;

	delete ptr->cPtr;
	delete ptr;
}