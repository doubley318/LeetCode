/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums)
    {
        for (int& i : nums) {
            if (i != 0)
                return false;
        }
        return true;
    }

    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.length(), n2 = word2.length();
        if (n1 != n2) {
            return false;
        }
        vector<int> nums1(26, 0), nums2(26, 0);
        for (int i = 0; i < n1; i++) {
            nums1[word1[i] - 'a']++;
            nums2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (nums1[i] == nums2[i]) {
                nums1[i] = 0;
                nums2[i] = 0;
            }
        }
        while (!check(nums1)) {
            for (int i = 0; i < 26; i++) {
                if (nums1[i] != 0) {
                    int j = 0;
                    for (; j < 26; j++) {
                        if (nums2[j] == nums1[i] && nums1[j] != 0) {
                            break;
                        }
                    }
                    if (j == 26) {
                        return false;
                    }
                    nums1[i] = nums1[j];
                    nums1[j] = 0;
                    nums2[j] = 0;
                }
            }
        }
        return true;
    }
};
// @lc code=end
