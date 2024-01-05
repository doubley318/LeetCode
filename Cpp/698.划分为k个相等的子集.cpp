/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % k != 0) {
            return false;
        }
        sum = sum / k;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        vector<int> newNums;
        for (int i : nums) {
            if (i > sum) {
                return false;
            } else if (i == sum) {
                k--;
            } else {
                newNums.push_back(i);
                mp[i]++;
            }
        }
        // 将newNums数组分成k个部分，每个部分都是sum
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(newNums[newNums.size() - i - 1]);
        }
        for (int i = k; i < newNums.size(); i++) {
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp + newNums[newNums.size() - i - 1]);
        }
        while (!pq.empty()) {
            if (pq.top() != sum)
                return false;
            pq.pop();
        }
        return true;
    }
};
// @lc code=end
