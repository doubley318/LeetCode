#include "mylib.h"

/*class Solution
{
public:
    bool mycomp(string s1, string s2)
    {
        int t1 = s1.find_first_of(" ");
        int t2 = s2.find_first_of(" ");
        if (s1.substr(t1) > s2.substr(t2))
            return false;
        else if (s1.substr(t1) < s2.substr(t2))
            return true;
        else
        {
            if (s1.substr(0, t1) > s2.substr(0, t2))
                return false;
            else
                return true;
        }
    }

    bool comp(string s1, string s2)
    {
        return s1 > s2;
    }

    vector<string> reorderLogFiles(vector<string> &s)
    {
        int r = s.size() - 1;
        int count = 0;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (isdigit(s[r][s[r].length() - 1]))
                r--, count++;
            else if (isdigit(s[i][s[i].length() - 1]))
            {
                string s = s[i];
                s[i] = s[r];
                s[r] = s;
                r--;
                count++;
            }
        }
        stable_sort(s.begin(), s.begin() + s.size() - count, mycomp);
        return s;
    }
};
*/

bool comp(string s1, string s2)
{
    return (s1 > s2);
}
bool c(int n1, int n2)
{
    return (n1 < n2);
}
bool mycomp(string s1, string s2)
{
    int t1 = 0;
    int t2 = 0;
    if (s1.substr(t1) > s2.substr(t2))
        return false;
    else if (s1.substr(t1) < s2.substr(t2))
        return true;
    else
    {
        if (s1.substr(0, t1) > s2.substr(0, t2))
            return false;
        else
            return true;
    }
}
int main()
{
    string s = "asss";
    cout << s.find("s") << s.substr(1) << s.substr(0, 1);
    return 0;
}