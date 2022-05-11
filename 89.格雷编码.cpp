/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<int> ans1 = {0, 1};
        vector<int> ans2 = {0, 1, 3, 2};
        if (n == 1)
            return ans1;
        if (n == 2)
            return ans2;
        ans = ans2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = pow(2, i - 1);
                for (int j = ans.size() - 1; j >= 0; j--)
                    ans.push_back(tmp + ans[j]);
        }
        return ans;
    }
};
// @lc code=end

