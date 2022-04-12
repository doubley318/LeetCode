/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        map<int, int> nums_map;
        int maxhz = 1;
        int ans = 60000;
        for (int i : nums)
        {
            auto j = nums_map.find(i);
            if (j == nums_map.end())
                nums_map.insert(pair<int, int>{i, 1});
            else
            {
                j->second++;
                if (maxhz < j->second)
                    maxhz = j->second;
            }
        }
        for (auto i : nums_map)
        {
            if (i.second == maxhz)
            {
                int l = 0;
                int r = nums.size() - 1;
                while (l < r)
                {
                    if (nums[l] == nums[r] && nums[l] == i.first)
                        break;
                    if (nums[l] != i.first)
                        l++;
                    if (nums[r] != i.first)
                        r--;
                }
                ans = min(ans, (r - l + 1));
            }
        }
        return ans;
    }
};
// @lc code=end
