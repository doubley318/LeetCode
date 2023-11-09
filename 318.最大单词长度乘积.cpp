/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int ret = 0, n = words.size();
        vector<int> nums(n, 0);
        auto [] string2int(string & s)
        {
            int tmp = 0;
            for (char& c : s) {
                tmp |= ((c - '0') << 1);
            }
            return tmp;
        };
        for (int i = 0; i < n; i++) {
            nums[i] = string2int(word[i]);
        }
        return ret;
    }
};
// @lc code=end
