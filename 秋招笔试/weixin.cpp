#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class A {
public:
    virtual void Print(int a)
    {
        cout << a << endl;
    }
};

class B : public A {
public:
    void Print(int a, int c)
    {
        cout << a + c << endl;
    }

    void Print(int a)
    {
        cout << a + 1000 << endl;
    }
};

int main()
{
    A a;
    B b;
    a.Print(10);
    b.Print(10);
    b.Print(10, 10);
    return 0;
}