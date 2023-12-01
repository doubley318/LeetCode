/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串

int main()
{
    Solution so;
    // 3
    string s = "b";
    cout << so.longestPalindrome(s) << endl;
    return 0;
}
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
            return "";
        string res;
        int l = 0, r = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int l = i;
            int r = i + 1;
            int len = 0;
            while (l >= 0 && r < s.size())
            {
                if (s[l] == s[r])
                {
                    r++;
                    l--;
                    len += 2;
                }
                else
                    break;
            }
            int L = i - 1;
            int R = i + 1;
            int Len = 1;
            while (L >= 0 && R < s.size())
            {
                if (s[L] == s[R])
                {
                    L--;
                    R++;
                    Len += 2;
                }
                else
                    break;
            }
            string tmp;
            if (Len > len && Len > max)
            {
                max = Len;
                for (int a = 0; a < Len; a++)
                    tmp += s[a + L + 1];
                res = tmp;
            }
            else if (len > max)
            {
                max = len;
                for (int a = 0; a < len; a++)
                    tmp += s[a + l + 1];
                res = tmp;
            }
        }
        return res;
    }
};
// @lc code=end
