/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jin = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            jin = digits[i] + jin;
            digits[i] = jin % 10;
            jin = jin / 10;
        }
        if (jin == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end

