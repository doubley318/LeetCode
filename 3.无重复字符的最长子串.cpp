/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
int main()
{
    string s = "   ";
    Solution so;
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int r = 0;
        int res = 0;
        vector<int> v(130);
        for (int i = 0; i < s.size(); i++)
        {
            r++;
            if (v[s[i]] == 0)
            {
                v[s[i]] = 1;
            }
            else
            {
                while (s[l] != s[i])
                {
                    v[s[l]] = 0;
                    l++;
                }
                l++;
            }

            res = res > (r - l) ? res : (r - l);
        }
        return res;
    }
};
// @lc code=end
