/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s)
    {
        bool res = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (!res && s[i] == '1')
            {
                res = true;
                i++;
                while (i < s.size())
                {
                    if (s[i] == '1')
                        i++;
                    else
                        break;
                }
            }
            if (res && s[i] == '1')
                return false;
        }
        return res;
    }
};
// @lc code=end

