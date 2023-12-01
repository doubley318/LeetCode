/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ans;
        int ai = a.length() - 1;
        int bi = b.length() - 1;
        int jin = 0;
        while (bi >= 0 || ai >= 0 || jin == 1)
        {
            char ax = ai < 0 ? '0' : a[ai];
            char bx = bi < 0 ? '0' : b[bi];
            jin = ax + bx - '0' - '0' + jin;
            ans = (char)(jin % 2 + '0') + ans;
            jin = jin / 2;
            ai--;
            bi--;
        }
        return ans;
    }
};
// @lc code=end

