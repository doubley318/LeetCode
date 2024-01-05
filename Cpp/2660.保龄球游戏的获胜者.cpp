/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int getSum(const vector<int>& nums)
    {
        int sum = 0, pre1 = 0, pre2 = 0;
        for (const int& i : nums) {
            if (pre1 == 10 || pre2 == 10) {
                sum += 2 * i;
            } else {
                sum += i;
            }
            pre1 = pre2;
            pre2 = i;
        }
        return sum;
    }

    int isWinner(vector<int>& player1, vector<int>& player2)
    {
        int ret = getSum(player1) - getSum(player2);
        if (ret > 0) {
            return 1;
        } else if (ret < 0) {
            return 2;
        } else {
            return 0;
        }
    }
};
// @lc code=end
