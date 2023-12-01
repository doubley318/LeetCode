/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> dp1(n, 0);
        int ball = (boxes[0] == '1');
        for (int i = 1; i < n; i++)
        {
            dp1[i] = dp1[i - 1] + ball;
            ball += (boxes[i] == '1');
        }
        vector<int> dp2(n, 0);
        ball = (boxes[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--)
        {
            dp2[i] = dp2[i + 1] + ball;
            ball += (boxes[i] == '1');
        }
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++)
        {
            ret[i] = dp1[i] + dp2[i];
        }
        return ret;
    }
};
// @lc code=end
