/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 *
 * [2866] 美丽塔 II
 */

// @lc code=start
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        int n = maxHeights.size();
        vector<long long> numsl(n + 1, 0);
        vector<long long> numsr(n + 1, 0);
        // 单调栈
        stack<pair<int, int>> stal;
        stal.push({ 0, 0 });
        for (int i = 0; i < n; i++) {
            int tmp = maxHeights[i];
            numsl[i + 1] = numsl[i] + tmp;
            int locl = 0, locr = i + 1;
            while (stal.top().first >= tmp) {
                locl = stal.top().second;
                numsl[i + 1] -= (long long)(stal.top().first - tmp) * (locr - locl);
                locr = locl;
                stal.pop();
            }
            stal.push({ tmp, locr });
        }
        stack<pair<int, int>> star;
        star.push({ 0, n });
        for (int i = n - 1; i >= 0; i--) {
            int tmp = maxHeights[i];
            numsr[i] = numsr[i + 1] + tmp;
            int locl = i, locr = n;
            while (star.top().first >= tmp) {
                locr = star.top().second;
                numsr[i] -= (long long)(star.top().first - tmp) * (locr - locl);
                locl = locr;
                star.pop();
            }
            star.push({ tmp, locl });
        }
        long long ret = 0;
        for (int i = 1; i <= n; i++) {
            ret = max(numsl[i] + numsr[i], ret);
        }
        return ret;
    }
};
// @lc code=end
