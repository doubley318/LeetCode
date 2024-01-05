/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        int ju = (tomatoSlices - 2 * cheeseSlices) / 2;
        int small = cheeseSlices - ju;
        if (ju >= 0 && small >= 0 && ju * 4 + small * 2 == tomatoSlices) {
            return { ju, small };
        } else {
            return {};
        }
    }
};
// @lc code=end
