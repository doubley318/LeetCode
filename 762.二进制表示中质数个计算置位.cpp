/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        set<int> primer = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = left; i <= right; i++)
        {
            int tmp = i;
            int count = 0;
            while (tmp > 0)
            {
                tmp = tmp - (tmp & -tmp);
                count++;
            }
            if (primer.find(count) != primer.end())
                ans++;
        }
        return ans;
    }
};
// @lc code=end

