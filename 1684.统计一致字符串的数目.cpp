/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        vector<int> a(26, 0);
        int ret = 0;
        for (int i = 0; i < allowed.size(); i++)
        {
            a[allowed[i] - 'a']++;
        }
        for (int i = 0; i < words.size(); i++)
        {
            bool y = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (a[words[i][j] - 'a'] == 0)
                {
                    y = false;
                    break;
                }
            }
            if (y)
                ret++;
        }
        return ret;
    }
};
// @lc code=end

