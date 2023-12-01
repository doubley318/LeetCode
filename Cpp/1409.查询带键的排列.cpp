/*
 * @lc app=leetcode.cn id=1409 lang=cpp
 *
 * [1409] 查询带键的排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        // 每个数所在的位置
        vector<int> location(m + 1, 0);
        // 每个位置的数字
        vector<int> nums(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            location[i + 1] = i;
            nums[i] = i + 1;
        }
        int n = queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            int q = queries[i];
            res[i] = location[q];
            int pre = nums[0];
            for (int j = 0; j < location[q]; j++)
            {
                location[nums[j]]++;
                int tmp = nums[j];
                nums[j] = pre;
                pre = tmp;
            }
            nums[location[q]] = pre;
            nums[0] = q;
            location[q] = 0;
        }
        return res;
    }
};
// @lc code=end
