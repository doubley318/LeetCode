#include "mylib.h"
class Solution
{
public:
    char firstUniqChar(string s)
    {
        vector<int> tmp(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (tmp[s[i] - 'a'] == 0)
                tmp[s[i] - 'a'] = i + 1;
            else
                tmp[s[i] - 'a'] = -100;
        }
        int t = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (tmp[i] > 0 && t > tmp[i])
            {
                t = tmp[i];
            }
        }
        if (t == INT_MAX)
            return ' ';
        else
            return s[t - 1];
    }
};

int main()
{
    return 0;
}