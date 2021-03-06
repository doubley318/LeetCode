/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        int res = 0;
        char tmp = s[0];
        map<char, int> xs = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); i++)
        {
            if (xs[tmp] < xs[s[i]])
                res = res + xs[s[i]] - 2 * xs[tmp];
            else
                res = res + xs[s[i]];
            tmp = s[i];
        }
        return res;
    }
};
// @lc code=end

