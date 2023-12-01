/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int tmp = arr[0], count = 0;
        for (int i = 1; count < k && i < arr.size(); i++)
        {
            if (tmp > arr[i])
            {
                count++;
            }
            else
            {
                tmp = arr[i];
                count = 1;
            }
        }
        return tmp;
    }
};
// @lc code=end
