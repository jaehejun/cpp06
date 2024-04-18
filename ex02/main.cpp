#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <typeinfo>

class D : public Base
{
};

Base *generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    switch (rand() % 3)
    {
    case (0):
        std::cout << "A generated" << std::endl;
        return new A;
    case (1):
        std::cout << "B generated" << std::endl;
        return new B;
    case (2):
        std::cout << "C generated" << std::endl;
        return new C;
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Failed Dynamic cast!" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

//// <typeinfo> 사용시
//void identify(Base *p)
//{
//	if (typeid(*p) == typeid(A))
//		std::cout << "A" << std::endl;
//	else if (typeid(*p) == typeid(B))
//		std::cout << "B" << std::endl;
//	else if (typeid(*p) == typeid(C))
//		std::cout << "C" << std::endl;
//	else
//		std::cout << "Unknown Type!" << std::endl;
//}

//void identify(Base &p)
//{
//	if (typeid(p) == typeid(A))
//		std::cout << "A" << std::endl;
//	else if (typeid(p) == typeid(B))
//		std::cout << "B" << std::endl;
//	else if (typeid(p) == typeid(C))
//		std::cout << "C" << std::endl;
//	else
//		std::cout << "Unknown Type!" << std::endl;
//}

int main()
{
    Base *ptr = generate();

    identify(ptr);
    identify(*ptr);
	std::cout << std::endl;

    std::cout << "@@@@@Case of D(Unknown Type)@@@@@" << std::endl;

    D *dptr = new D();
    identify(dptr);
    identify(*dptr);
	std::cout << std::endl;

	std::cout << "@@@@@Case of Base type@@@@@" << std:: endl;
	Base *base = new Base;
	identify(base);
	identify(*base);

    delete ptr;
    delete dptr;
	delete base;
    return 0;
}
