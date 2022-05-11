/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        if (start == end)
            return ans;
        ans = 1;
        vector<string> diff1;
        vector<string> diff2;
        for (string i : bank)
        {
            int diff_count = 0;
            for (int j = 0; j < i.length(); j++)
            {
                if (start[j] != i[j])
                {
                    diff_count++;
                    if (diff_count > 1)
                        break;
                }
            }
            if (diff_count == 2)
                diff2.push_back(i);
            else if (diff_count == 1)
                diff1.push_back(i);
        }
        int tmp_ans = 20;
        if (diff1.size() == 0)
            return -1;
        for (string i : diff1)
        {
            int t = minMutation(i, end, diff2);
            if (t == -1)
                t = 20;
            tmp_ans = min(t + ans, tmp_ans);
        }
        if (tmp_ans > 10)
            return -1;
        return tmp_ans;
    }
};
// @lc code=end

