/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            string tmp;
            char t = ans[0];
            int count = 1;
            for (int j = 1; j < ans.size(); j++)
            {
                if (ans[j] == t)
                    count++;
                else
                {
                    tmp = tmp + (char)(count + '0') + t;
                    t = ans[j];
                    count = 1;
                }
            }
            tmp = tmp + (char)(count + '0') + t;
            ans = tmp;
        }
        return ans;
    }
};
// @lc code=end

