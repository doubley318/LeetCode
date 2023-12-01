/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mostable = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> word_mos;
        for (int i = 0; i < words.size(); i++)
        {
            string tmp;
            for (int j = 0; j < words[i].length(); j++)
                tmp = tmp + mostable[words[i][j] - 'a'];
            if (word_mos.find(tmp) == word_mos.end())
                word_mos.insert(tmp);
        }
        return word_mos.size();
    }
};
// @lc code=end

