/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k)
    {
        priority_queue<int, vector<int>, less<int>> nums;
        int sum = 0;
        for (int& i : piles) {
            nums.push(i);
            sum += i;
        }
        for (int i = 0; i < k; i++) {
            int tmp = nums.top();
            sum -= (nums.top() / 2);
            nums.pop();
            nums.push(tmp - tmp / 2);
        }
        return sum;
    }
};
// @lc code=end
