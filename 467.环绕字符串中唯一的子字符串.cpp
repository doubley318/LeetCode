/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> s(26, 0);
        int ans = 0;
        for (int i = 0; i < p.length(); i++)
        {
            s[p[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++)
            if (s[i] == 1)
                ans++;
        int l = 1;
        while (l != p.length())
        {
            for (int i = 0; i < p.length() - l; i++)
            {
                if (s[i] == l && p[i + l] - 'a' == (p[i - 1 + l] + 1 - 'a') % 26)
                    ans++, s[i]++;
            }
            l++;
        }
        return ans;
    }
};
// @lc code=end

