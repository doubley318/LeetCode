/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
//Your runtime beats 68.75 % of cpp submissions
//Your memory usage beats 61.55 % of cpp submissions (57.6 MB)
//Your runtime beats 52.43 % of cpp submissions
//Your memory usage beats 48.04 % of cpp submissions (57.6 MB)
// @lc code=start
class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int maxarea = 0;
        int l = 0;
        int r = height.size() - 1;
        for (int i = 0; i < height.size() && r != l; i++)
        {
            maxarea = max((r - l) * (height[r] < height[l] ? height[r] : height[l]), maxarea);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};
// @lc code=end

