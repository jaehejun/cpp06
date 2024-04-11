#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
//forbidden functions : std::typeinfo

Base *generate(void)
{
	//randomly instaciates A/B/C
	//return instance as a Base pointer

	srand(static_cast<unsigned int>(time(NULL)));
	//int target(rand() % 3);

	switch(rand() % 3)
	{
		case(0):
			std::cout << "A generated" << std::endl;
			return dynamic_cast<Base *>(new A);
		case(1):
			std::cout << "B generated" << std::endl;
			return dynamic_cast<Base *>(new B);
		case(2):
			std::cout << "C generated" << std::endl;
			return dynamic_cast<Base *>(new C);
	}
	return NULL;
}

// prints the actual type of the object pointed by p: A/B/C
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

// prints the actual type of the object pointed by p: A/B/C
// using a pointer inside this function is forbidden
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		//std::cout << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		//std::cout << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		//std::cout << e.what() << std::endl;
		std::cout << "Unknown type" << std::endl;
	}
	
}

int main()
{
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
