/*
 * @lc app=leetcode.cn id=1806 lang=cpp
 *
 * [1806] 还原排列的最少操作步数
 */

// @lc code=start
class Solution
{
public:
    int reinitializePermutation(int n)
    {
        int *perm = (int *)malloc(sizeof(int) * n);
        int *arr = (int *)malloc(sizeof(int) * n);
        int N = n / 2;
        for (int i = 0; i < n; i++)
            perm[i] = i;
        bool ret = false;
        int ans = 0;
        while (!ret)
        {
            ret = true;
            for (int i = 0; i < n / 2; i++)
            {
                arr[i * 2] = perm[i];
                arr[i * 2 + 1] = perm[N + i];
                if (arr[i * 2] != i * 2 || arr[i * 2 + 1] != i * 2 + 1)
                    ret = false;
            }
            memcpy(perm, arr, sizeof(int) * n);
            ans++;
        }
        return ans;
    }
};
// @lc code=end
