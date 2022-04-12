/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// Your runtime beats 58.2 % of cpp submissions
// Your memory usage beats 96.45 % of cpp submissions (17.6 MB)
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> s = strs;
        map<string, int> m;
        int k = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            sort(s[i].begin(), s[i].end());
            if (m.find(s[i]) == m.end())
                m.insert(pair<string, int>{s[i], k++});
        }
        vector<vector<string>> res(k, vector<string>(0));
        for (int j = 0; j < strs.size(); j++)
            res[m.find(s[j])->second].push_back(strs[j]);
        return res;
    }
};
// @lc code=end
