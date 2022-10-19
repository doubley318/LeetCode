#include "mylib.h"
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    queue<int> a;
    a.push(1);
    a.push(2);
    cout << a.back();
    return 0;
}