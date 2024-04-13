#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

struct Data
{
	char* cPtr;
	char character;
	int number;
};

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif