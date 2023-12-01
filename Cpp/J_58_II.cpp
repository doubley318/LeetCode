#include "mylib.h"

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        return s.substr(n % s.size()) + s.substr(0, n % s.size());
    }
};

int main()
{
    return 0;
}