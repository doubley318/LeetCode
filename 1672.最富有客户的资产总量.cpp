/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int i = 1; i < accounts[0].size(); i++)
            for (int j = 0; j < accounts.size(); j++)
                accounts[j][i] += accounts[j][i - 1];
        for (int i = 0; i < accounts.size(); i++)
            ans = max(accounts[i][accounts[0].size() - 1], ans);
        return ans;
    }   
};
// @lc code=end

