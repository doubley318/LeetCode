/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution
{
public:
    static bool compare1(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
    static bool compare2(int a, int b)
    {
        return a > b;
    }

    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end(), compare2);
        vector<pair<int, int>> tmp;
        vector<int> ret(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++)
            tmp.push_back({nums2[i], i});
        sort(tmp.begin(), tmp.end(), compare1);
        int l = 0, r = nums1.size() - 1;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (nums1[l] <= tmp[i].first)
            {
                ret[tmp[i].second] = nums1[r];
                r--;
            }
            else
            {
                ret[tmp[i].second] = nums1[l];
                l++;
            }
        }
        return ret;
    }
};
// @lc code=end
