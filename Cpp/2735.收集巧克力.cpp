/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
class Solution {
public:
    long long minCost(vector<int>& nums, int x)
    {
        // 相当于用x代价让0-n的价格的nums全部向前移动了一个
        int n = nums.size();
        vector<vector<int>> mp(n, vector<int>(n, 0));
        long long ret = 0;
        for (int j = 0; j < n; j++) {
            mp[0][j] = nums[j];
            ret += nums[j];
        }
        for (int i = 1; i < n; i++) {
            // 移动n次每个商品价格的最低值
            long long tmpRet = x;
            tmpRet *= i;
            for (int j = 0; j < n; j++) {
                mp[i][j] = min(mp[i - 1][j], nums[(j - i + n) % n]);
                tmpRet += mp[i][j];
            }
            ret = min(tmpRet, ret);
        }
        return ret;
    }
};
// @lc code=end
