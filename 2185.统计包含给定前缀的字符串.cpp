/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int ret = 0, n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (words[i].size() < pref.size())
                continue;
            int j = 0;
            for (; j < pref.size(); j++)
                if (pref[j] != words[i][j])
                    break;
            if (j == pref.size())
                ret++;
        }
        return ret;
    }
};
// @lc code=end

