//// class type-casting
// #include <iostream>
// using namespace std;

// class Dummy
//{
//     double i, j;
// };

// class Addition
//{
//     int x, y;

//  public:
//    Addition(int a, int b)
//    {
//        x = a;
//        y = b;
//    }
//    int result()
//    {
//        return x + y;
//    }
//};

// int main()
//{
//     Dummy d;
//     Addition *padd;
//     padd = (Addition *)&d;
//     cout << padd->result();
//     return 0;
// }

#include <exception>
#include <iostream>
using namespace std;

class Base
{
    virtual void dummy()
    {
    }
};
class Derived : public Base
{
    int a;
};

int main()
{
    try
    {
        Base *pba = new Derived;
        Base *pbb = new Base;

        //Derived *pd = new Derived;

        pd = dynamic_cast<Derived *>(pba);
        if (pd == 0)
            cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived *>(pbb);
        if (pd == 0)
            cout << "Null pointer on second type-cast.\n";
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what();
    }
    return 0;
}