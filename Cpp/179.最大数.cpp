/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
public:
    void sortji(vector<string> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int s = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[j] + nums[s]) > (nums[s] + nums[j]))
                {
                    swap(nums[j], nums[s]);
                }
            }
        }
    }

    string largestNumber(vector<int> &nums)
    {
        string ret;
        vector<vector<string>> ji_sort(10);
        for (int i : nums)
        {
            string s = to_string(i);
            ji_sort[s[0] - '0'].push_back(s);
        }
        for (vector<string> &i : ji_sort)
            sortji(i);
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < ji_sort[i].size(); j++)
            {
                ret = ret + ji_sort[i][j];
            }
        }
        return ret[0] == '0' ? "0" : ret;
    }
};
// @lc code=end
