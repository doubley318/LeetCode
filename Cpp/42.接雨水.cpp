/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int tmp = height.size() - 1;
        int res = 0;
        vector<int> right(height.size());
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (height[tmp] < height[i])
                tmp = i;
            right[i] = tmp;
        }
        for (int i = 0; i < height.size() - 1; i++)
        {
            if (height[left] < height[i])
                left = i;
            tmp = min(height[left], height[right[i]]);
            res += tmp - height[i];
        }
        return res;
    }
};
// @lc code=end

