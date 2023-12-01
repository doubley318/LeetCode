/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> al(26, 0);
        stack<char> sta;
        vector<int> nums(26, 0);
        for (auto i : s)
            al[i - 'a']++;
        for (auto i : s)
        {
            if (nums[i - 'a'] == 0)
            {
                while (!sta.empty() && sta.top() > i)
                {
                    if (al[sta.top() - 'a'] != 0)
                    {
                        nums[sta.top() - 'a']--;
                        sta.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                sta.push(i);
                nums[i - 'a']++;
            }
            al[i - 'a']--;
        }
        string ret;
        while (!sta.empty())
        {
            ret = sta.top() + ret;
            sta.pop();
        }
        return ret;
    }
};
// @lc code=end
