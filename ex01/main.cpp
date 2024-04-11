#include "Serializer.hpp"

int main()
{
	Data data;
	Data *ptr;
	ptr = &data;
	Data *deserialize;
	uintptr_t number;

	number = Serializer::serialize(ptr);
	std::cout << number << std::endl;

	deserialize = Serializer::deserialize(number);
	std::cout << "Comparing deserialize() quals to original pointer ptr" << std::endl; 
	std::cout <<  deserialize << std::endl;
	std::cout <<  ptr << std::endl;
}