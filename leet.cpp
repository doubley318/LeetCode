#include "mylib.h"

class Solution
{
public:
    bool huiwen(string s)
    {
        int i = 0;
        while (i <= s.length() / 2)
        {
            if (s[i] != s[s.length() - 1 - i])
                return false;
            i++;
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        
    }
};

int main()
{
    Solution so;
    if (so.huiwen("vavav"))
        cout << "yes!" << endl;
    else
        cout << "no!!" << endl;
    return 0;
}