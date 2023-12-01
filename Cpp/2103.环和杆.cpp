/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints(string rings)
    {
        int n = rings.length();
        vector<int> nums(10, 0);
        for (int i = 0; i < n; i += 2) {
            switch (rings[i]) {
            case 'R':
                nums[rings[i + 1] - '0'] |= 1;
                break;
            case 'B':
                nums[rings[i + 1] - '0'] |= 2;
                break;
            case 'G':
                nums[rings[i + 1] - '0'] |= 4;
            default:
                break;
            }
        }
        int ret = 0;
        for (int& i : nums) {
            if (i == 7)
                ret++;
        }
        return ret;
    }
};
// @lc code=end
