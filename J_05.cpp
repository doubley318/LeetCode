#include "mylib.h"

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;
        for (char &i : s)
        {
            if (i == ' ')
                res = res + "%20";
            else
                res = res + i;
        }
        return res;
    }
};

int main()
{
    return 0;
}