/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int ret = 0, tmp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            tmp = max(tmp, arr[i]);
            if (tmp == i)
                ret++;
        }
        return ret;
    }
};
// @lc code=end
