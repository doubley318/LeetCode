#include <iostream>
using namespace std;

class Solution
{
public:
    int sumNums(int n)
    {
        n && (n = n + sumNums(n - 1));
        return n;
    }
};

int main()
{
    return 0;
}