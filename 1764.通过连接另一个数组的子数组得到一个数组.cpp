/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */

// @lc code=start
class Solution
{
public:
    int in(vector<int> g, vector<int> nums, int r)
    {
        for (int i = r; i < nums.size(); i++)
        {
            if (g[0] == nums[i])
            {
                int j = i;
                for (; j - i < g.size() && j < nums.size(); j++)
                {
                    if (g[j - i] != nums[j])
                        break;
                }
                if (j - i == g.size())
                    return j;
            }
        }
        return -1;
    }
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int n = groups.size(), m = nums.size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            r = in(groups[i], nums, r);
            if (r == -1)
                return false;
        }
        return true;
    }
};
// @lc code=end
