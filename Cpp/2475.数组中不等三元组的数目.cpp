/*
 * @lc app=leetcode.cn id=2475 lang=cpp
 *
 * [2475] 数组中不等三元组的数目
 */

// @lc code=start
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        unordered_map<int, int> myMap;
        for (int &i : nums)
        {
            myMap[i]++;
        }
        if (myMap.size() < 3)
            return 0;
        int res = 0, tmp = 0;
        for (auto &i : myMap)
        {
            res += tmp * i.second * (nums.size() - tmp - i.second);
            tmp += i.second;
        }
        return res;
    }
};
// @lc code=end
