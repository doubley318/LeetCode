/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m - 1, r = n - 1;
        int target = nums1.size() - 1;
        while (l >= 0 && r >= 0)
        {
            if (nums1[l] > nums2[r])
            {
                nums1[target] = nums1[l];
                l--;
            }
            else
            {
                nums1[target] = nums2[r];
                r--;
            }
            target--;
        }
        while (r >= 0)
        {
            nums1[target] = nums2[r];
            target--;
            r--;
        }
        return;
    }
};
// @lc code=end

