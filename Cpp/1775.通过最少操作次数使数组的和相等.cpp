/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = 0, sum2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> num1(7, 0);
        vector<int> num2(7, 0);
        for (int i = 0; i < n1; i++)
        {
            sum1 += nums1[i];
            num1[nums1[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            sum2 += nums2[i];
            num2[nums2[i]]++;
        }
        if (n1 * 6 < n2 || n1 > n2 * 6)
            return -1;
        int ret = 0;
        if (sum1 == sum2)
            return 0;
        if (sum1 > sum2)
        {
            swap(sum1, sum2);
            swap(n1, n2);
            swap(num1, num2);
        }
        // sum1<sum2
        int l = 1, r = 6;
        int sub = sum2 - sum1;
        while (num1[l] == 0)
        {
            l++;
        }
        while (num2[r] == 0)
        {
            r--;
        }
        while (sub > 0)
        {
            if (r - 1 >= 6 - l)
            {
                num2[r]--;
                sub = sub - r + 1;
                while (r >= 1 && num2[r] == 0)
                {
                    r--;
                }
            }
            else
            {
                num1[l]--;
                sub = sub - 6 + l;
                while (l <= 6 && num1[l] == 0)
                {
                    l++;
                }
            }
            ret++;
        }
        return ret;
    }
};
// @lc code=end
