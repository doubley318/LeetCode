/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char i : s)
        {
            if (!res.empty() && res.top() == m.find(i)->second)
                res.pop();
            else
                res.push(i);
        }
        return res.empty() ? true : false;
    }
};
// @lc code=end

