/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int n = nums.size();
        vector<int> l(n, 0);
        l[0] = nums[0];
        vector<int> r(n, 0);
        r[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            l[i] = l[i - 1] + nums[i];
            r[n - i - 1] = r[n - i] + nums[n - i - 1];
        }
        int a = 0, b = n - 1;
        int ret = INT_MAX;
        for (; a < n; a++)
        {
            if (l[a] == x)
            {
                ret = a + 1;
                break;
            }
            else if (l[a] > x)
                break;
        }
        if (a == n)
            return -1;
        a--;
        while (a >= 0 && b >= 0)
        {
            if (l[a] + r[b] == x)
            {
                ret = min(ret, a + 1 + n - b);
                a--;
                b--;
            }
            else if (l[a] + r[b] > x)
            {
                a--;
            }
            else
            {
                b--;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (r[i] == x)
            {
                ret = min(ret, n - i);
                break;
            }
            else if (r[i] > x)
            {
                break;
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
// @lc code=end
