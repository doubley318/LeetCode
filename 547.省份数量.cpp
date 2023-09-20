/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isVisited[i]) {
                continue;
            }
            isVisited[i] = true;
            stack<int> sta;
            sta.push(i);
            while (!sta.empty()) {
                int tmp = sta.top();
                sta.pop();
                for (int j = 0; j < n; j++) {
                    if (isConnected[tmp][j] == 1 && isVisited[j] == false) {
                        sta.push(j);
                        isVisited[j] = true;
                    }
                }
            }
            res++;
        }
        return res;
    }
};
// @lc code=end
