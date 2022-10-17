#include "mylib.h"
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int i = 11;
    cout << (i++ * 1 / 3) << endl;
    return 0;
}