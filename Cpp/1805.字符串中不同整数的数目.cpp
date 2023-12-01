/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        unordered_set<string> s;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            while (i < n && word[i] <= '9' && word[i] >= '0')
            {
                tmp = tmp + word[i];
                i++;
            }
            int x = 0;
            while (x < (-1 + (int)tmp.size()))
            {
                if (tmp[x] != '0')
                    break;
                x++;
            }
            tmp = tmp.substr(x);
            if (tmp.size() != 0)
                s.insert(tmp);
        }
        return s.size();
    }
};
// @lc code=end

