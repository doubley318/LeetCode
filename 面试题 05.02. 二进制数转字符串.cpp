#include "mylib.h"

class Solution
{
public:
    string printBin(double num)
    {
        string res = "0.";
        for (int i = 0; i < 30; i++)
        {
            num = num * 2;
            if (num == 1)
                return res + "1";
            else if (num > 1)
            {
                num = num - 1;
                res = res + "1";
            }
            else
                res = res + "0";
        }
        return "ERROR";
    }
};

int main()
{
    return 0;
}