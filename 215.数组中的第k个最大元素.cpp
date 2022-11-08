/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, cmp> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pq.size() < k)
            {
                pq.push(nums[i]);
            }
            else
            {
                if (nums[i] > pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
// @lc code=end
