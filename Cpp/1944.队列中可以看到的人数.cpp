/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights)
    {
        // 从右往左，单调栈
        int n = heights.size();
        vector<int> ret(n, 0);
        stack<int> sta;
        sta.push(heights[n - 1]);
        // 比本身大的那几个
        for (int i = n - 2; i >= 0; i--) {
            int tmp = 0;
            while (!sta.empty() && sta.top() < heights[i]) {
                sta.pop();
                tmp++;
            }
            if (sta.empty()) {
                ret[i] = tmp;
            } else {
                ret[i] = tmp + 1;
            }
            sta.push(heights[i]);
        }
        return ret;
    }
};
// @lc code=end
