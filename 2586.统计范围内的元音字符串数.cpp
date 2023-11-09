/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right)
    {
        unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
        int ret = 0;
        for (; left <= right; left++) {
            if ((vowel.find(*words[left].begin()) != vowel.end()) && (vowel.find(*(words[left].end() - 1)) != vowel.end())) {
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end
