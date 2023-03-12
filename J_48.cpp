#include "mylib.h"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        while (r < n)
        {
            while (m[s[r]] != 0)
            {
                m[s[l]]--;
                l++;
            }
            m[s[r]] = 1;
            r++;
            res = max(r - l, res);
        }
        return res;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution so;
    cout << so.lengthOfLongestSubstring(s);
    return 0;
}