/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
        set<char> yuan = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        for (int i = 0; i < sentence.length(); i++)
        {
            count++;
            if (yuan.find(sentence[i]) != yuan.end())
            {
                i++;
                while (i < sentence.length())
                {
                    if (sentence[i] == ' ')
                        break;
                    i++;
                }
                sentence.insert(i, "ma");
                i += 2;
            }
            else
            {
                string tmp(1, sentence[i]);
                sentence.erase(i, 1);
                while (i < sentence.length())
                {
                    if (sentence[i] == ' ')
                        break;
                    i++;
                }
                sentence.insert(i, tmp + "ma");
                i += 3;
            }
            for (int j = 0; j < count; j++)
                sentence.insert(i, "a"), i++;
        }
        return sentence;
    }
};
// @lc code=end

