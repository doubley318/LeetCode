class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        int a[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            a[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            if (--a[s2[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};