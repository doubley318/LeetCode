/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution
{
public:
    vector<int> num;
    Solution(vector<int> &nums)
    {
        num = nums;
    }

    int pick(int target)
    {
        int count = 0, ans;
        for (int i = 0; i < num.size(); i++)
            if (num[i] == target)
                count++, ans = (rand() % count) == 0 ? i : ans;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
