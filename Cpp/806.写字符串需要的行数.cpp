/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1, col = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (col + widths[s[i] - 'a'] > 100)
                col = widths[s[i] - 'a'], row++;
            else
                col = col + widths[s[i] - 'a'];
        }
        return {row, col};
    }
};
// @lc code=end

